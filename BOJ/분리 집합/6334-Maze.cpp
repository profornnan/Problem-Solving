#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct UnionFind {
	vector<int> parent;
	vector<int> cnt;

	UnionFind(int sz) : parent(sz, -1), cnt(sz, 1) {}

	int Find(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int a, int b) {
		int pa = Find(a);
		int pb = Find(b);
		if (pa == pb) return;
		parent[pb] = pa;
		cnt[pa] += cnt[pb];
		cnt[pb] = 0;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int tc = 0;

	while (true) {
		int H, W;
		cin >> W >> H;

		if (H == 0 && W == 0)
			break;

		const int N = H + W;

		int ans = 0;
		int maxCnt = 0;
		UnionFind uf(N * N);

		for (int y = 0; y < H; ++y) {
			const int r = W - 1 + y;
			const int c = y;

			for (int x = 0; x < W; ++x) {
				char ch;
				cin >> ch;

				int lu = (r - x) * N + c + x;
				int ru = (r - x) * N + c + x + 1;
				int ld = (r - x + 1) * N + c + x;
				int rd = (r - x + 1) * N + c + x + 1;

				if (ch == '/')
					swap(ru, ld);

				if (uf.Find(lu) == uf.Find(ru)) {
					++ans;
					maxCnt = max(maxCnt, uf.cnt[uf.Find(lu)]);
				}
				else
					uf.Union(lu, ru);

				if (uf.Find(ld) == uf.Find(rd)) {
					++ans;
					maxCnt = max(maxCnt, uf.cnt[uf.Find(ld)]);
				}
				else
					uf.Union(ld, rd);
			}
		}

		cout << "Maze #" << ++tc << ":\n";

		if (ans)
			cout << ans << " Cycles; the longest has length " << maxCnt << ".\n";
		else
			cout << "There are no cycles.\n";

		cout << '\n';
	}

	return 0;
}
