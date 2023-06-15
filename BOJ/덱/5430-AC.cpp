#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int sz;
		string commands;

		cin >> commands >> sz;
		deque<int> dq(sz);

		cin.get(); cin.get();

		for (int& num : dq) {
			cin >> num;
			cin.get();
		}

		cin.get();

		bool rev = false, err = false;;

		for (char& command : commands) {
			if (command == 'R')
				rev = !rev;
			else {
				if (dq.empty()) {
					err = true;
					break;
				}
				rev ? dq.pop_back() : dq.pop_front();
			}
		}

		if (err) {
			cout << "error\n";
			continue;
		}

		cout << '[';

		if (rev) {
			for (int i = dq.size() - 1; i >= 0; i--) {
				cout << dq[i];
				if (i != 0) cout << ',';
			}
		}
		else {
			for (int i = 0; i < dq.size(); i++) {
				cout << dq[i];
				if (i != dq.size() - 1) cout << ',';
			}
		}

		cout << "]\n";
	}

	return 0;
}
