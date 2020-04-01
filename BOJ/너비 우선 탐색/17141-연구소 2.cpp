#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 987654321;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n, m, room_cnt, min_time = INF;
int board[50][50], dist[50][50];
vector<pair<int, int> > virus;
int selected[10];

void solve(int cnt, int last) {
	if (cnt == m) {
		int time = 0, cnt = 0;
		memset(dist, -1, sizeof(dist));
		queue<pair<int, int> > q;
		for (int i = 0; i < m; i++) {
			int y = virus[selected[i]].first;
			int x = virus[selected[i]].second;
			dist[y][x] = 0;
			q.push({ y, x });
		}
		while (true) {
			int q_size = q.size();
			for (int k = 0; k < q_size; k++) {
				int y = q.front().first;
				int x = q.front().second;
				cnt++;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (0 <= ny && ny < n && 0 <= nx && nx < n) {
						if (board[ny][nx] == 0 && dist[ny][nx] == -1) {
							dist[ny][nx] = dist[y][x] + 1;
							q.push({ ny, nx });
						}
					}
				}
			}
			if (q.empty())
				break;
			time++;
		}
		if (cnt == room_cnt)
			min_time = min_time < time ? min_time : time;
		return;
	}
	for (int i = last + 1; i < virus.size(); i++) {
		selected[cnt] = i;
		solve(cnt + 1, i);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> board[y][x];
			if (board[y][x] == 2) {
				board[y][x] = 0;
				virus.push_back({ y, x });
			}
			if (board[y][x] != 1)
				room_cnt++;
		}
	}
	solve(0, -1);
	if (min_time != INF)
		cout << min_time << '\n';
	else
		cout << "-1\n";
	return 0;
}
