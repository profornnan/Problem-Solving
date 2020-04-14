#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n, m, ans = 987654321;
int board[50][50], dist[50][50];
vector<pair<int, int> > store, house;
vector<int> selected;

void solve(int cnt, int last) {
	if (cnt == m) {
		memset(dist, -1, sizeof(dist));
		queue<pair<int, int> > q;
		for (int i = 0; i < m; i++) {
			int now = selected[i];
			q.push({ store[now].first, store[now].second });
			dist[store[now].first][store[now].second] = 0;
		}
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (0 <= ny && ny < n && 0 <= nx && nx < n) {
					if (dist[ny][nx] == -1) {
						dist[ny][nx] = dist[y][x] + 1;
						q.push({ ny, nx });
					}
				}
			}
		}
		int store_dist = 0;
		for (int i = 0; i < house.size(); i++)
			store_dist += dist[house[i].first][house[i].second];
		ans = ans < store_dist ? ans : store_dist;
		return;
	}
	for (int i = last + 1; i < store.size(); i++) {
		selected.push_back(i);
		solve(cnt + 1, i);
		selected.pop_back();
	}
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> board[y][x];
			if (board[y][x] == 1)
				house.push_back({ y, x });
			if (board[y][x] == 2)
				store.push_back({ y, x });
		}
	}
	solve(0, -1);
	cout << ans << '\n';
	return 0;
}
