#include <iostream>
#include <queue>
using namespace std;

const int MAX = 500'000;
int n, k;
bool visited[MAX + 1][2];		// location, time % 2

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n >> k;
	int time = 0, dist = 0;
	queue<int> q;
	visited[n][time % 2] = true;
	q.push(n);
	while (true) {
		k += dist;
		dist++;
		if (k > MAX) {
			cout << -1 << '\n';
			break;
		}
		if (visited[k][time % 2]) {
			cout << time << '\n';
			break;
		}
		int q_size = q.size();
		while (q_size--) {
			int now = q.front();
			q.pop();
			int next = now - 1, n_time = (time + 1) % 2;
			if (next >= 0 && !visited[next][n_time]) {
				visited[next][n_time] = true;
				q.push(next);
			}
			next = now + 1;
			if (next <= MAX && !visited[next][n_time]) {
				visited[next][n_time] = true;
				q.push(next);
			}
			next = now * 2;
			if (next <= MAX && !visited[next][n_time]) {
				visited[next][n_time] = true;
				q.push(next);
			}
		}
		time++;
	}
	return 0;
}
