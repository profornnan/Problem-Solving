#include <iostream>
#include <queue>
#include <cstring>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n, m, max_cnt;
int city[20][20];
bool visited[20][20];

void solve(int sy, int sx) {
	memset(visited, false, sizeof(visited));
	int k = 0, cnt = 0;
	queue<pair<int, int> > q;
	visited[sy][sx] = true;
	q.push({ sy, sx });
	while (!q.empty()) {
		int q_size = q.size();
		k++;
		for (int j = 0; j < q_size; j++) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (city[y][x] == 1)
				cnt++;
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (0 <= ny && ny < n && 0 <= nx && nx < n) {
					if (visited[ny][nx] == false) {
						visited[ny][nx] = true;
						q.push({ ny, nx });
					}
				}
			}
		}
		int profit = cnt * m - (k * k + (k - 1) * (k - 1));
		if (profit >= 0)
			max_cnt = max_cnt > cnt ? max_cnt : cnt;
	}
}

int main(void)
{
	sws;
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cout << '#' << t << ' ';
		cin >> n >> m;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				cin >> city[y][x];
		max_cnt = 0;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				solve(y, x);
		cout << max_cnt << '\n';
	}
	return 0;
}
