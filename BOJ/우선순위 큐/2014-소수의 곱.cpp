#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int K, N;
	cin >> K >> N;

	vector<int> primes(K);
	priority_queue<long long> pq;

	for (auto& prime : primes) {
		cin >> prime;
		pq.push(-prime);
	}

	for (int i = 0; i < N - 1; ++i) {
		const long long now = -pq.top();
		pq.pop();

		for (const auto& prime : primes) {
			pq.push(-prime * now);

			if (now % prime == 0)
				break;
		}
	}

	cout << -pq.top() << '\n';

	return 0;
}
