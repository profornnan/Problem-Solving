#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	long long K;

	cin >> str >> K;

	--K;

	for (int i = str.size() - 1; i >= 0; --i) {
		auto& ch = str[i];

		if (ch == '1' || ch == '6') {
			ch = K & 1 ? '6' : '1';
			K >>= 1;
		}
		else if (ch == '2' || ch == '7') {
			ch = K & 1 ? '7' : '2';
			K >>= 1;
		}
	}

	cout << (K ? "-1" : str) << '\n';

	return 0;
}
