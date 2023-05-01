#include <iostream>
#include <string>
using namespace std;

int N;
char arr[101];

void dfs(int cur) {
	if (cur > N) return;

	dfs(cur * 2);
	cout << arr[cur];
	dfs(cur * 2 + 1);
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	for (int tc = 1; tc <= 10; tc++) {
		cout << '#' << tc << ' ';
		cin >> N;
		cin.ignore();
		
		for (int i = 1; i <= N; i++) {
			string str;
			getline(cin, str);
			arr[i] = str[str.find(' ') + 1];
		}
		
		dfs(1);
		cout << '\n';
	}

	return 0;
}
