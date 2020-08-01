#include <iostream>
#include <string>
#include <map>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, m, k;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);

	cin >> n >> m;

	map<string, int> rows;
	string s;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> s;
		rows[s]++;
	}

	cin >> k;

	for (auto row : rows) {
		string n_str = row.first;
		int zero_cnt = 0;

		for (int i = 0; i < n_str.size(); i++)
			if (n_str[i] == '0')
				zero_cnt++;

		if (zero_cnt > k || (k - zero_cnt) % 2 != 0)
			continue;

		ans = ans > row.second ? ans : row.second;
	}

	cout << ans << '\n';

	return 0;
}
