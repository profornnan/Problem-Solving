#include <iostream>
using namespace std;

void star(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		cout << ' ';
	else if (n / 3 == 0)
		cout << '*';
	else
		star(i, j, n / 3);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			star(i, j, N);
		cout << '\n';
	}

	return 0;
}
