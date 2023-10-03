#include <iostream>
#include <string>
using namespace std;

int N;

void dfs(int num, int sum, int operand, string path) {
	if (num > N) {
		if (sum + operand == 0)
			cout << path << '\n';
		return;
	}

	dfs(num + 1, sum, operand * 10 + (operand > 0 ? num : -num), path + " " + to_string(num));
	dfs(num + 1, sum + operand, num, path + "+" + to_string(num));
	dfs(num + 1, sum + operand, -num, path + "-" + to_string(num));
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		cin >> N;
		dfs(2, 0, 1, "1");
		cout << '\n';
	}

	return 0;
}
