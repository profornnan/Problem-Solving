#include <iostream>
using namespace std;

constexpr int MAX_N = 10;

int N;
char sign[MAX_N][MAX_N];
int seq[MAX_N];
bool validSeq;

bool isValidInt(int idx) {
	int sum = 0;

	for (int i = idx; i >= 0; --i) {
		sum += seq[i];
		const char s = sign[i][idx];

		if ((s == '0' && sum != 0) || (s == '-' && sum >= 0) || (s == '+' && sum <= 0))
			return false;
	}

	return true;
}

void dfs(int idx) {
	if (validSeq)
		return;

	if (idx >= N) {
		validSeq = true;

		for (int i = 0; i < N; ++i)
			cout << seq[i] << ' ';
		cout << '\n';

		return;
	}

	const char s = sign[idx][idx];

	seq[idx] = 0;

	if (s == '0') {
		if (isValidInt(idx))
			dfs(idx + 1);

		return;
	}

	const int d = s == '-' ? -1 : 1;

	for (int i = 0; i < 10; ++i) {
		seq[idx] += d;

		if (isValidInt(idx))
			dfs(idx + 1);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = i; j < N; ++j)
			cin >> sign[i][j];

	dfs(0);

	return 0;
}
