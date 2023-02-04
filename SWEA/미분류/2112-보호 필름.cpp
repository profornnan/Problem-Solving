#include <iostream>
#include <cstring>
using namespace std;

const int INF = 987654321;
int T, D, W, K;
int cnt, min_cnt;
int film[13][20];
int path[13];

int processed_num(int y, int x) {
	if (path[y] == 0)
		return 0;
	else if (path[y] == 1)
		return 1;
	return film[y][x];
}

bool is_valid() {
	for (int x = 0; x < W; x++) {
		bool pass = false;
		int flag = processed_num(0, x), cnt = 1;
		for (int y = 1; y < D; y++) {
			int num = processed_num(y, x);

			if ((flag + num) % 2 == 1) {
				flag = num;
				cnt = 0;
			}

			cnt++;

			if (cnt >= K) {
				pass = true;
				break;
			}
		}

		if (pass == false)
			return false;
	}

	return true;
}

void dfs(int row) {
	if (row >= D) {
		if (is_valid() && min_cnt > cnt)
			min_cnt = cnt;
		return;
	}

	if (min_cnt <= cnt)
		return;

	dfs(row + 1);

	for (int i = 0; i < 2; i++) {
		path[row] = i;
		cnt++;
		dfs(row + 1);
		cnt--;
		path[row] = -1;
	}
}

int main(void) {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cout << '#' << t + 1 << ' ';

		cin >> D >> W >> K;

		for (int y = 0; y < D; y++)
			for (int x = 0; x < W; x++)
				cin >> film[y][x];

		min_cnt = INF;
		memset(path, -1, sizeof(path));

		dfs(0);

		cout << min_cnt << '\n';
	}

	return 0;
}