#include <iostream>
#include <vector>
using namespace std;

constexpr int MOD = 1'000'003;

class SquareMatrix {
private:
	int N;
	vector<vector<int>> mat;

public:
	SquareMatrix(const int& N) : N(N), mat(N, vector<int>(N)) {}
	SquareMatrix(const vector<vector<int>>& mat) : N(mat.size()), mat(mat) {}

	SquareMatrix operator*(const SquareMatrix& rhs) const {
		SquareMatrix temp(N);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < N; ++k)
					temp.mat[i][j] += (static_cast<long long>(mat[i][k]) * rhs.mat[k][j]) % MOD;

				temp.mat[i][j] %= MOD;
			}
		}

		return temp;
	}

	vector<int>& operator[](const int& row) {
		return mat[row];
	}

	static SquareMatrix identity(const int& N) {
		SquareMatrix temp(N);

		for (int i = 0; i < N; ++i)
			temp[i][i] = 1;

		return temp;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, S, E, T;
	cin >> N >> S >> E >> T;
	--S; --E;

	SquareMatrix adj(N * 5);

	for (int i = 0; i < N; ++i)
		for (int cnt = 1; cnt <= 4; ++cnt)
			adj[i * 5 + cnt][i * 5 + cnt - 1] = 1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char cnt;
			cin >> cnt;
			cnt -= '0';

			if (cnt == 0)
				continue;

			adj[i * 5][j * 5 + cnt - 1] = 1;
		}
	}

	SquareMatrix ans = SquareMatrix::identity(N * 5);

	while (T) {
		if (T & 1)
			ans = ans * adj;

		adj = adj * adj;
		T >>= 1;
	}

	cout << ans[S * 5][E * 5] << '\n';

	return 0;
}
