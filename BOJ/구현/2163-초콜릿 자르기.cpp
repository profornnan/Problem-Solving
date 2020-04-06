#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	cout << n * m - 1 << '\n';
	return 0;
}
