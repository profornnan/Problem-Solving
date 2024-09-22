#include <iostream>
#include <string>
using namespace std;

bool visited[4];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	cin >> str;

	if (str.back() == '4') {
		for (int i = 1; i <= 3; ++i)
			cout << str.substr(0, str.length() - 1) << i << '\n';

		return 0;
	}

	while (str.length() > 1) {
		const int num = str.back() - '0';
		str.pop_back();

		if (!visited[num]) {
			cout << str << 4 << '\n';
			visited[num] = true;
		}
	}

	return 0;
}
