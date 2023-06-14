#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int cnt = 0;
	vector<int> A(N);
	vector<bool> visited(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		cnt++;

		int now = i;
		
		while (!visited[now]) {
			visited[now] = true;
			now = A[now];
		}
	}

	if (cnt == 1) cnt = 0;

	cout << cnt << '\n';

	return 0;
}
