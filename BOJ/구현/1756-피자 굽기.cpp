#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> oven(N);
	vector<int> dough(M);

	for (int& o : oven)
		cin >> o;

	for (int& d : dough)
		cin >> d;

	int last = oven[0];

	for (int i = 0; i < N; ++i)
		last < oven[i] ? oven[i] = last : last = oven[i];

	int idx = 0;
	int ans = 0;

	for (int i = N - 1; i >= 0; --i) {
		if (dough[idx] > oven[i])
			continue;

		if (++idx == M) {
			ans = i + 1;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}
