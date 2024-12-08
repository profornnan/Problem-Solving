#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

constexpr int SIZE = 32'768;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;
	cin.ignore();

	for (int tc = 1; tc <= T; ++tc) {
		cout << "PROGRAM #" << tc << ":\n";

		string commands;

		while (true) {
			string str;
			getline(cin, str);

			if (str == "end")
				break;

			str.erase(remove(str.begin(), str.end(), ' '), str.end());
			commands += str.substr(0, str.find('%'));
		}

		int now = 0;
		stack<int> stk;
		unordered_map<int, int> jump;

		for (; now < commands.size(); ++now) {
			if (commands[now] == '[')
				stk.push(now);
			else if (commands[now] == ']') {
				if (stk.empty())
					break;

				const int prev = stk.top();
				stk.pop();
				jump[prev] = now;
				jump[now] = prev;
			}
		}

		if (now != commands.size() || !stk.empty()) {
			cout << "COMPILE ERROR\n";
			continue;
		}

		int ptr = 0;
		vector<unsigned char> arr(SIZE);

		for (int i = 0; i < commands.size(); ++i) {
			switch (commands[i]) {
			case '>':
				ptr = (ptr + 1) % SIZE;
				break;
			case '<':
				ptr = (ptr + SIZE - 1) % SIZE;
				break;
			case '+':
				++arr[ptr];
				break;
			case '-':
				--arr[ptr];
				break;
			case '.':
				cout << arr[ptr];
				break;
			case '[':
				if (arr[ptr] == 0)
					i = jump[i];
				break;
			case ']':
				if (arr[ptr] != 0)
					i = jump[i];
				break;
			}
		}

		cout << '\n';
	}

	return 0;
}
