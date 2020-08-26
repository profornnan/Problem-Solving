#include <iostream>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int OFFSET = 15;

int dx[] = { 1, -1, 0, 0 };  // E, W, S, N
int dy[] = { 0, 0, 1, -1 };
int n;
int percent[4];
bool visited[31][31];
double ans;

void dfs(int cnt, int y, int x, double per) {
	if (cnt == n) {
		ans += per;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(cnt + 1, ny, nx, per * percent[i] / 100);
			visited[ny][nx] = false;
		}
	}
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cout << fixed;
	cout.precision(10);
	cin >> n;
	for (int i = 0; i < 4; i++)
		cin >> percent[i];
	visited[OFFSET][OFFSET] = true;
	dfs(0, OFFSET, OFFSET, 1);
	cout << ans << '\n';
	return 0;
}
