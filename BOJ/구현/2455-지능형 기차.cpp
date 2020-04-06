#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	int out, in, people = 0, ans = 0;
	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		people += in - out;
		ans = ans > people ? ans : people;
	}
	cout << ans << '\n';
	return 0;
}
