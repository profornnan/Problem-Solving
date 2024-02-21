#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1'000'000'007;

class SquareMatrix {
private:
	int N;
	vector<vector<long long>> mat;

public:
	SquareMatrix(int N) : N(N), mat(N, vector<long long>(N)) {}
	SquareMatrix(const vector<vector<long long>>& mat) : N(mat.size()), mat(mat) {}

	SquareMatrix operator*(const SquareMatrix& rhs) {
		SquareMatrix temp(N);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < N; ++k)
					temp.mat[i][j] += (mat[i][k] * rhs.mat[k][j]) % MOD;

				temp.mat[i][j] %= MOD;
			}
		}

		return temp;
	}

	vector<long long>& operator[](const int& row) {
		return mat[row];
	}

	static SquareMatrix identity(int N) {
		SquareMatrix temp(N);

		for (int i = 0; i < N; ++i)
			temp.mat[i][i] = 1;

		return temp;
	}

	int size() const {
		return N;
	}

	void print() {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				cout << mat[i][j] << ' ';
			cout << '\n';
		}
	}
};

int T, N, D;
vector<SquareMatrix> adj;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T >> N >> D;

	vector<SquareMatrix>(T, N).swap(adj);

	for (int t = 0; t < T; ++t) {
		int M;
		cin >> M;

		while (M--) {
			int from, to, cnt;
			cin >> from >> to >> cnt;
			adj[t][from - 1][to - 1] = cnt;
		}
	}

	int cycleCnt = D / T;
	int remainCnt = D % T;

	SquareMatrix ans = SquareMatrix::identity(N);
	SquareMatrix cycle = SquareMatrix::identity(N);

	for (int i = 0; i < T; ++i)
		cycle = cycle * adj[i];

	while (cycleCnt) {
		if (cycleCnt & 1)
			ans = ans * cycle;

		cycle = cycle * cycle;
		cycleCnt >>= 1;
	}

	for (int i = 0; i < remainCnt; ++i)
		ans = ans * adj[i];

	ans.print();

	return 0;
}
