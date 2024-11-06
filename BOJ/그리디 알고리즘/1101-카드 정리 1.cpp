#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_N = 50;
constexpr int MAX_M = 50;

int N, M;
int boxes[MAX_N][MAX_M];
bool used[MAX_M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> boxes[i][j];

	int ans = N;

	for (int joker = 0; joker < N; ++joker) {
		int moveCnt = 0;
		memset(used, 0, sizeof(used));

		for (int i = 0; i < N; ++i) {
			if (joker == i)
				continue;

			int colorCnt = 0;
			int colorIdx = 0;

			for (int j = 0; j < M; ++j) {
				if (boxes[i][j]) {
					++colorCnt;
					colorIdx = j;
				}
			}

			if (colorCnt == 0)
				continue;
			else if (colorCnt == 1)
				used[colorIdx] ? ++moveCnt : used[colorIdx] = true;
			else
				++moveCnt;
		}

		ans = ans < moveCnt ? ans : moveCnt;
	}

	cout << ans << '\n';

	return 0;
}
