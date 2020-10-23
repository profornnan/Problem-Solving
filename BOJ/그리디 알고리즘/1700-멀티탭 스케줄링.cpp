#include <iostream>
#include <vector>
#include <set>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int INF = 987654321;
int N, K;

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> K;

	int unplug_cnt = 0;
	set<int> multitap;
	vector<int> appliances(K, 0);

	for (int i = 0; i < K; i++)
		cin >> appliances[i];

	for (int i = 0; i < appliances.size(); i++) {
		int appliance = appliances[i];

		if (multitap.size() < N) {
			multitap.insert(appliance);
			continue;
		}

		if (multitap.find(appliance) != multitap.end())
			continue;

		int unplug_app = 0, max_next_use = 0;

		for (auto using_app : multitap) {
			int next_use = INF;

			for (int j = i + 1; j < appliances.size(); j++) {
				if (appliances[j] == using_app) {
					next_use = j;
					break;
				}
			}

			if (max_next_use < next_use) {
				max_next_use = next_use;
				unplug_app = using_app;
			}
		}

		multitap.erase(unplug_app);
		multitap.insert(appliance);
		unplug_cnt++;
	}

	cout << unplug_cnt << '\n';

	return 0;
}
