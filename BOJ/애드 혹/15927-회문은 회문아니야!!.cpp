#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	cin >> str;

	bool allSame = true;

	for (int i = 0; i < str.size() / 2; ++i) {
		if (str[i] != str[str.size() - 1 - i]) {
			cout << str.size() << '\n';
			return 0;
		}

		if (str[i] != str[i + 1])
			allSame = false;
	}

	cout << (allSame ? -1 : static_cast<int>(str.size()) - 1) << '\n';

	return 0;
}
