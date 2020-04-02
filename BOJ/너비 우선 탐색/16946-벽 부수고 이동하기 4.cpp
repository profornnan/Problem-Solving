#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int n, m;
char board[1000][1000];
int area[1000][1000];
vector<int> cell_num;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> board[y][x];
			area[y][x] = -1;
		}
	}
	int area_num = -1;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (board[r][c] != '1' && area[r][c] == -1) {
				int cnt = 0;
				area_num++;
				queue<pair<int, int> > q;
				area[r][c] = area_num;
				q.push({ r, c });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					cnt++;
					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (0 <= ny && ny < n && 0 <= nx && nx < m) {
							if (board[ny][nx] != '1' && area[ny][nx] == -1) {
								area[ny][nx] = area_num;
								q.push({ ny, nx });
							}
						}
					}
				}
				cell_num.push_back(cnt);
			}
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (board[y][x] == '0') {
				cout << 0;
			}
			else {
				int cnt = 1;
				set<int> adj_area;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (0 <= ny && ny < n && 0 <= nx && nx < m) {
						if (area[ny][nx] != -1) {
							adj_area.insert(area[ny][nx]);
						}
					}
				}
				for (auto area_num : adj_area) {
					cnt += cell_num[area_num];
				}
				cout << cnt % 10;
			}
		}
		cout << '\n';
	}
	return 0;
}
