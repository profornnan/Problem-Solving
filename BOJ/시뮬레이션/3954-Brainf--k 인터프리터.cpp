#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

constexpr unsigned char MAX_UC = 255;
constexpr int MAX_CNT = 50'000'000;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int M, C, I;
		cin >> M >> C >> I;

		vector<unsigned char> memories(M);

		string commands, inputs;
		cin >> commands >> inputs;

		stack<int> stk;
		vector<int> jump(C);

		for (int now = 0; now < C; ++now) {
			if (commands[now] == '[')
				stk.push(now);
			else if (commands[now] == ']') {
				const int prev = stk.top();
				stk.pop();
				jump[prev] = now;
				jump[now] = prev;
			}
		}

		bool terminated = true;
		int memoryIdx = 0, commandIdx = 0, inputIdx = 0, cnt = 0, minCommandIdx = C, maxCommandIdx = 0;

		while (commandIdx < C) {
			if (cnt > MAX_CNT) {
				if (!terminated)
					break;

				terminated = false;
				cnt = 0;
			}

			const char command = commands[commandIdx];

			if (command == '-') {
				--memories[memoryIdx];
			}
			else if (command == '+') {
				++memories[memoryIdx];
			}
			else if (command == '<') {
				memoryIdx = (memoryIdx + M - 1) % M;
			}
			else if (command == '>') {
				memoryIdx = (memoryIdx + 1) % M;
			}
			else if (command == '[') {
				if (memories[memoryIdx] == 0)
					commandIdx = jump[commandIdx];
			}
			else if (command == ']') {
				if (memories[memoryIdx] != 0)
					commandIdx = jump[commandIdx];
			}
			else if (command == ',') {
				memories[memoryIdx] = inputIdx == I ? MAX_UC : inputs[inputIdx++];
			}

			++commandIdx;
			++cnt;

			if (!terminated) {
				minCommandIdx = minCommandIdx < commandIdx ? minCommandIdx : commandIdx;
				maxCommandIdx = maxCommandIdx > commandIdx ? maxCommandIdx : commandIdx;
			}
		}

		if (terminated)
			cout << "Terminates\n";
		else
			cout << "Loops" << ' ' << minCommandIdx - 1 << ' ' << maxCommandIdx << '\n';
	}

	return 0;
}
