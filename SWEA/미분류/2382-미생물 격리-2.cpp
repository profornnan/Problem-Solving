#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
	int y;
	int x;
	int num;
	int dir;
	int alive;
	int merged;
};

int dx[] = { 1, 0, -1, 0 };  // R U L D
int dy[] = { 0, -1, 0, 1 };
int input_to_dir[] = { 0, 1, 3, 2, 0 };

int N, M, K;
int MAP[100][100];
vector<Node> v;

void func() {
	memset(MAP, -1, sizeof(MAP));

	for (int i = 0; i < K; i++) {
		if (!v[i].alive) continue;

		Node& now = v[i];

		now.y += dy[now.dir];
		now.x += dx[now.dir];

		if (now.y == 0 || now.y == N - 1 || now.x == 0 || now.x == N - 1) {
			now.dir = (now.dir + 2) % 4;
			now.num /= 2;
			if (now.num == 0) now.alive = 0;
			continue;
		}

		if (MAP[now.y][now.x] != -1) {
			Node& node = v[MAP[now.y][now.x]];

			if (node.num > now.num) {
				node.merged += now.num;
				now.alive = 0;
			}
			else {
				now.merged = node.num + node.merged;
				node.alive = 0;
				MAP[now.y][now.x] = i;
			}
		}
		else
			MAP[now.y][now.x] = i;
	}

	for (int i = 0; i < K; i++) {
		if (!v[i].alive || !v[i].merged) continue;
		v[i].num += v[i].merged;
		v[i].merged = 0;
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';
		cin >> N >> M >> K;

		v = vector<Node>(K);

		for (int i = 0; i < K; i++) {
			cin >> v[i].y >> v[i].x >> v[i].num >> v[i].dir;
			v[i].dir = input_to_dir[v[i].dir];
			v[i].alive = 1;
		}

		for (int i = 0; i < M; i++)
			func();

		int ans = 0;

		for (auto node : v)
			if (node.alive)
				ans += node.num;

		cout << ans << '\n';
	}

	return 0;
}
