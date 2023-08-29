#include <iostream>
#include <vector>
using namespace std;

const int dx[]{ 1, 0, -1, 0 };  // R, U, L, D
const int dy[]{ 0, -1, 0, 1 };

struct Pos {
	int y;
	int x;
};

class UnionFind {
private:
	vector<int> parent;

public:
	UnionFind(int sz) : parent(sz, -1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pb] = pa;
	}

	int groupCnt() {
		int cnt = 0;

		for (const int& p : parent)
			if (p == -1)
				++cnt;

		return cnt;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> MAP(N, vector<int>(M));
	UnionFind uf(N * M);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char ch;
			cin >> ch;

			switch (ch) {
			case 'R':
				MAP[y][x] = 0;
				break;
			case 'U':
				MAP[y][x] = 1;
				break;
			case 'L':
				MAP[y][x] = 2;
				break;
			case 'D':
				MAP[y][x] = 3;
				break;
			default:
				break;
			}
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			Pos now = { y, x };
			Pos next = { y, x };

			int idx = 0;
			int nidx = 0;

			do {
				now = next;
				next = { now.y + dy[MAP[now.y][now.x]], now.x + dx[MAP[now.y][now.x]] };
				
				idx = now.y * M + now.x;
				nidx = next.y * M + next.x;
				
				uf.Union(idx, nidx);
			} while (uf.Find(idx) != uf.Find(nidx));
		}
	}

	cout << uf.groupCnt() << '\n';

	return 0;
}
