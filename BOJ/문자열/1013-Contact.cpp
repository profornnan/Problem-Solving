#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	regex re("(100+1+|01)+");

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		string str;
		cin >> str;
		cout << (regex_match(str, re) ? "YES" : "NO") << '\n';
	}

	return 0;
}
