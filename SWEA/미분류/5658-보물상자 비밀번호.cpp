#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

int N, K;
string s;

int main(void) {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';
		cin >> N >> K;
		cin >> s;
		s += s;

		int len = N / 4;
		unordered_set<string> hex;
		vector<int> bin;

		for (int i = 0; i < N; i++)
			hex.insert(s.substr(i, len));

		for (auto it = hex.begin(); it != hex.end(); it++) {
			string now = *it;
			int num = 0;
			for (int i = 0; i < len; i++) {
				if (now[i] >= 'A' && now[i] <= 'F')
					num += (now[i] - 'A' + 10) * pow(16, len - i - 1);
				else
					num += (now[i] - '0') * pow(16, len - i - 1);
			}
			bin.push_back(num);
		}

		sort(bin.begin(), bin.end(), greater<int>());

		cout << bin[K - 1] << '\n';
	}

	return 0;
}
