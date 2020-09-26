#include <iostream>
#include <vector>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int L, ML, MK, C;
vector<int> street;

bool simulation() {
	queue<int> q;
	int power = 0;
	for (int idx = 0; idx <= L; idx++) {
		if (street[idx] - power > 0)
			return false;
		if (!q.empty()) {
			if (q.front() == idx) {
				power -= MK;
				q.pop();
			}
		}
		if (street[idx + 1] > power + MK && C > 0) {
			street[idx + 1] = 0;
			C--;
			continue;
		}
		power += MK;
		q.push(idx + ML);
	}
	return true;
}

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);
	cin >> L >> ML >> MK >> C;
	street = vector<int>(L + 2);
	for (int i = 0; i < L; i++)
		cin >> street[i + 1];
	if (simulation())
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
