#include <iostream>
using namespace std;

constexpr int MAX_N = 48;

int N;
int init[MAX_N];
int to[MAX_N];
int card[2][MAX_N];

bool isValid(int now) {
	for (int i = 0; i < N; ++i)
		if (card[now][i] != i % 3)
			return false;
	return true;
}

bool isCycle(int now) {
	for (int i = 0; i < N; ++i)
		if (card[now][i] != init[i])
			return false;
	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> init[i];
		card[0][i] = init[i];
	}

	for (int i = 0; i < N; ++i)
		cin >> to[i];

	int cnt = 0;

	while (true) {
		const int now = cnt % 2;
		const int next = (cnt + 1) % 2;

		if (isValid(now))
			break;

		if (cnt && isCycle(now)) {
			cnt = -1;
			break;
		}

		for (int from = 0; from < N; ++from)
			card[next][to[from]] = card[now][from];

		++cnt;
	}

	cout << cnt << '\n';

	return 0;
}
