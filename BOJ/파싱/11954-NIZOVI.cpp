#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	bool enter = false;
	int tab = 0;

	string str;
	cin >> str;

	for (const auto& ch : str) {
		if (ch == '{') {
			if (enter)
				cout << '\n' << string(tab, ' ');
			tab += 2;
			cout << ch;
			enter = true;
		}
		else if (ch == '}') {
			tab -= 2;
			cout << '\n' << string(tab, ' ');
			cout << ch;
			enter = true;
		}
		else if (ch == ',') {
			cout << ch;
			enter = true;
		}
		else {
			if (enter)
				cout << '\n' << string(tab, ' ');
			cout << ch;
			enter = false;
		}
	}

	cout << '\n';

	return 0;
}
