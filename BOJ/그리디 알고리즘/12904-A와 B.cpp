#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string s, t;
	cin >> s >> t;

	while (true) {
		if (s.size() == t.size())
			break;

		int now = t.back();
		t.pop_back();

		if (now == 'B')
			reverse(t.begin(), t.end());
	}

	cout << (s == t ? 1 : 0) << '\n';

	return 0;
}
