#include <iostream>
#include <vector>
#include <map>
#include <string>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

map<string, int> country;
pair<int, int> match[6];
double p[6][3], ans[4];
int score[4];

void solve(int cnt, double per) {
	if (cnt == 6) {
		map<int, vector<int> > rank;
		for (int i = 0; i < 4; i++)
			rank[-score[i]].push_back(i);
		int t = 2;
		for (auto item : rank) {
			if (t == 0)
				break;
			if (item.second.size() <= t) {
				for (int i = 0; i < item.second.size(); i++)
					ans[item.second[i]] += per;
				t -= item.second.size();
			}
			else {
				for (int i = 0; i < item.second.size(); i++)
					ans[item.second[i]] += per * t / item.second.size();
				t = 0;
			}
		}
		return;
	}
	int a = match[cnt].first, b = match[cnt].second;
	if (p[cnt][0] != 0) {
		score[a] += 3;
		solve(cnt + 1, per * p[cnt][0]);
		score[a] -= 3;
	}
	if (p[cnt][1] != 0) {
		score[a] += 1, score[b] += 1;
		solve(cnt + 1, per * p[cnt][1]);
		score[a] -= 1, score[b] -= 1;
	}
	if (p[cnt][2] != 0) {
		score[b] += 3;
		solve(cnt + 1, per * p[cnt][2]);
		score[b] -= 3;
	}
}

int main(void)
{
	sws;
	cout.precision(10);
	cout << fixed;
	freopen("input.txt", "r", stdin);
	string a, b;
	for (int i = 0; i < 4; i++) {
		cin >> a;
		country.insert({ a, i });
	}
	for (int i = 0; i < 6; i++) {
		cin >> a >> b;
		match[i] = { country[a], country[b] };
		cin >> p[i][0] >> p[i][1] >> p[i][2];
	}
	solve(0, 1);
	for (int i = 0; i < 4; i++)
		cout << ans[i] << '\n';
	return 0;
}
