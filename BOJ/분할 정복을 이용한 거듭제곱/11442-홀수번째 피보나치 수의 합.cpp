#include <iostream>
#include <vector>
using namespace std;

constexpr long long MOD = 1'000'000'007;

class SquareMatrix {
private:
	int N;
	vector<vector<long long>> mat;

public:
	SquareMatrix(int N) : N(N), mat(N, vector<long long>(N)) {}
	SquareMatrix(const vector<vector<long long>>& mat) : N(mat.size()), mat(mat) {}

	SquareMatrix operator*(const SquareMatrix& rhs) const {
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

	vector<long long>& operator[](const int row) {
		return mat[row];
	}

	static SquareMatrix identity(const int N) {
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

	long long K;
	cin >> K;

	K += K & 1;

	SquareMatrix ans(SquareMatrix::identity(2));
	SquareMatrix A({ {1, 1}, {1, 0} });

	while (K) {
		if (K & 1)
			ans = ans * A;

		A = A * A;
		K >>= 1;
	}

	cout << ans[1][0] << '\n';

	return 0;
}
