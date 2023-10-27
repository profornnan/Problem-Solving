#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	string ans;
	vector<int> sec(N + 1);
	vector<string> records(N + 1);

	for (int i = 1; i <= N; ++i) {
		string oper;
		cin >> oper;

		if (oper == "type") {
			char ch;
			cin >> ch >> sec[i];

			ans.push_back(ch);
			records[i] = ans;
		}
		else if (oper == "undo") {
			int t;
			cin >> t >> sec[i];

			int targetSec = sec[i] - t;
			int targetIdx = i;

			while (targetIdx > 0 && sec[targetIdx] >= targetSec)
				--targetIdx;

			ans = records[targetIdx];
			records[i] = ans;
		}
	}

	cout << ans << '\n';

	return 0;
}
