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
					temp.mat[i][j] += (mat[i][k] * rhs.mat[k][j]);

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
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int D;
	cin >> D;

	SquareMatrix A({
		{0, 1, 1, 0, 0, 0, 0, 0},
		{1, 0, 1, 1, 0, 0, 0, 0},
		{1, 1, 0, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 1, 0, 0},
		{0, 0, 1, 1, 0, 1, 1, 0},
		{0, 0, 0, 1, 1, 0, 0, 1},
		{0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 0, 0, 1, 1, 0}
	});

	SquareMatrix ans = SquareMatrix::identity(A.size());

	while (D) {
		if (D & 1)
			ans = ans * A;

		A = A * A;
		D >>= 1;
	}

	cout << ans[0][0] << '\n';

	return 0;
}
