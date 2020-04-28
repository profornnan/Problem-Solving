#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n, m, max_score;
int board[20][20];
bool visited[20][20];
vector<pair<int, int> > empty_pos;

void solve(int cnt, int last) {
	if (cnt == 2) {
		int total_score = 0;
		memset(visited, false, sizeof(visited));
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				if (board[r][c] == 2 && !visited[r][c]) {
					int score = 0;
					bool is_surrounded = true;
					queue<pair<int, int> > q;
					visited[r][c] = true;
					q.push({ r, c });
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						score++;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int ny = y + dy[i];
							int nx = x + dx[i];
							if (0 <= ny && ny < n && 0 <= nx && nx < m) {
								if (board[ny][nx] == 2 && !visited[ny][nx]) {
									visited[ny][nx] = true;
									q.push({ ny, nx });
								}
								else if (board[ny][nx] == 0)
									is_surrounded = false;
							}
						}
					}
					if (is_surrounded)
						total_score += score;
				}
			}
		}
		max_score = max_score > total_score ? max_score : total_score;
		return;
	}
	for (int i = last + 1; i < empty_pos.size(); i++) {
		board[empty_pos[i].first][empty_pos[i].second] = 1;
		solve(cnt + 1, i);
		board[empty_pos[i].first][empty_pos[i].second] = 0;
	}
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> board[y][x];
			if (board[y][x] == 0)
				empty_pos.push_back({ y, x });
		}
	}
	solve(0, -1);
	cout << max_score << '\n';
	return 0;
}
