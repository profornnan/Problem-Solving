#include <iostream>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	cout << m - gcd(n, m) << '\n';
	return 0;
}
