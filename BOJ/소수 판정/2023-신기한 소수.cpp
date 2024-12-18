#include <iostream>
using namespace std;

int N;

bool isPrime(const int num) {
	if (num < 2)
		return false;

	for (int i = 2; i * i <= num; ++i)
		if (num % i == 0)
			return false;

	return true;
}

void dfs(const int level, const int now) {
	if (level >= N) {
		cout << now << '\n';
		return;
	}

	for (int i = 0; i < 10; ++i) {
		const int next = now * 10 + i;

		if (isPrime(next))
			dfs(level + 1, next);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	dfs(0, 0);

	return 0;
}
