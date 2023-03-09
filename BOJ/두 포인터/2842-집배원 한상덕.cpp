#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
};

int dx[]{ 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[]{ 0, -1, -1, -1, 0, 1, 1, 1 };

int N;
char MAP[50][50];
int height[50][50];
int visited[50][50];
unordered_set<int> us;
int minK = 21e8, maxK;
int ans = 21e8, totalCnt;
Node st;

bool isValid(int low, int high) {
	if (low > minK || high < maxK)
		return false;

	queue<Node> q;
	q.push(st);

	memset(visited, 0, sizeof(visited));
	visited[st.y][st.x] = 1;

	int cnt = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (MAP[now.y][now.x] != '.')
			cnt++;

		for (int i = 0; i < 8; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx] != 0) continue;
			if (height[ny][nx] < low || height[ny][nx] > high) continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	return cnt == totalCnt;
}

int main(void) {
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> MAP[y][x];

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> height[y][x];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			us.insert(height[y][x]);

			if (MAP[y][x] != '.') {
				totalCnt++;
				minK = min(minK, height[y][x]);
				maxK = max(maxK, height[y][x]);

				if (MAP[y][x] == 'P')
					st = { y, x };
			}
		}
	}

	vector<int> h;

	for (int i : us)
		h.push_back(i);

	sort(h.begin(), h.end());

	int left = 0, right = 0;

	while (right < h.size()) {
		int low = h[left], high = h[right];

		if (isValid(low, high)) {
			ans = min(ans, high - low);
			left++;
		}
		else
			right++;
	}

	cout << ans << '\n';

	return 0;
}
