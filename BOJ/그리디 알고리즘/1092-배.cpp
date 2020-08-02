#include <iostream>
#include <algorithm>
#include <vector>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, m, cnt;
vector<int> crains;
vector<int> boxes;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);

	cin >> n;
	crains = vector<int>(n);

	for (int i = 0; i < n; i++)
		cin >> crains[i];

	cin >> m;
	boxes = vector<int>(m);

	for (int i = 0; i < m; i++)
		cin >> boxes[i];

	sort(crains.begin(), crains.end(), greater<int>());
	sort(boxes.begin(), boxes.end(), greater<int>());

	if (boxes.front() > crains.front()) {
		cout << "-1\n";
		return 0;
	}

	while (boxes.size()) {
		int idx = 0;

		for (int i = 0; i < boxes.size(); i++) {
			if (idx == crains.size())
				break;

			if (crains[idx] >= boxes[i]) {
				boxes.erase(boxes.begin() + i);
				idx++;
				i--;
			}
		}
		cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
