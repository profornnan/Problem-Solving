#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

constexpr int MAX_N = 8;

int N, K;
int digit[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	int st{}, en{};

	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;
		st = st * 10 + num;
	}

	for (int num = 1; num <= N; ++num)
		en = en * 10 + num;

	digit[N - 1] = 1;

	for (int i = N - 2; i >= 0; --i)
		digit[i] = digit[i + 1] * 10;

	queue<int> q;
	unordered_set<int> visited;

	int cnt = 0;
	q.push(st);
	visited.insert(st);

	while (!q.empty()) {
		int sz = q.size();

		while (sz--) {
			const int now = q.front();
			q.pop();

			if (now == en) {
				cout << cnt << '\n';
				return 0;
			}

			for (int left = 0; left <= N - K; ++left) {
				int right = left + K - 1;
				int next = now;

				for (int i = 0; i < K / 2; ++i) {
					const int leftNum = (next / digit[left + i]) % 10;
					const int rightNum = (next / digit[right - i]) % 10;

					next -= leftNum * digit[left + i] + rightNum * digit[right - i];
					next += rightNum * digit[left + i] + leftNum * digit[right - i];
				}

				if (visited.count(next))
					continue;

				q.push(next);
				visited.insert(next);
			}
		}

		++cnt;
	}

	cout << "-1\n";

	return 0;
}
