#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int y;
	int x;
};

int N, M, L, K;
Node star[100];
int maxCnt;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> L >> K;

	for (int i = 0; i < K; i++)
		cin >> star[i].y >> star[i].x;

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			int sy = min(star[i].y, star[j].y);
			int sx = min(star[i].x, star[j].x);
			int ey = sy + L;
			int ex = sx + L;
			int cnt = 0;

			for (int k = 0; k < K; k++)
				if (star[k].y >= sy && star[k].y <= ey && star[k].x >= sx && star[k].x <= ex)
					cnt++;

			maxCnt = max(maxCnt, cnt);
		}
	}

	cout << K - maxCnt << '\n';

	return 0;
}
