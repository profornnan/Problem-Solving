#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<pair<string, string>> ds{
	{"ababa", "bab"},
	{"babab", "aba"},
	{"acaca", "cac"},
	{"cacac", "aca"},
	{"bcbcb", "cbc"},
	{"cbcbc", "bcb"},
};

string res;

void solve(const string& str) {
	for (const auto& ch : str) {
		res.push_back(ch);

		const int N = res.size();

		if (N >= 2 && res[N - 1] == res[N - 2]) {
			res = res.substr(0, N - 2);
			continue;
		}

		if (N >= 5) {
			const string sub = res.substr(N - 5);

			for (const auto& [from, to] : ds) {
				if (sub == from) {
					res = res.substr(0, N - 5);
					solve(to);
					break;
				}
			}
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		string str;
		cin >> str;

		res.clear();
		solve(str);

		cout << (res.empty() ? "closed" : "open") << '\n';
	}

	return 0;
}
