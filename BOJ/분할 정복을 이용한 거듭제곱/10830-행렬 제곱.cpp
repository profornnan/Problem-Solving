#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
	int N;
	vector<vector<int>> mat;

public:
	SquareMatrix(int N) : N(N), mat(N, vector<int>(N)) {}

	SquareMatrix operator*(const SquareMatrix& rhs) {
		SquareMatrix temp(N);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < N; ++k)
					temp.mat[i][j] += (mat[i][k] * rhs.mat[k][j]);

				temp.mat[i][j] %= 1000;
			}
		}

		return temp;
	}

	static SquareMatrix identity(int N) {
		SquareMatrix temp(N);

		for (int i = 0; i < N; ++i)
			temp.mat[i][i] = 1;

		return temp;
	}

	void input() {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> mat[i][j];
	}

	int size() const {
		return N;
	}

	void show() const {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				cout << mat[i][j] << ' ';
			cout << '\n';
		}
	}
};

SquareMatrix pow(const SquareMatrix& A, long long m) {
	if (m == 0) return SquareMatrix::identity(A.size());
	if (m % 2 > 0) return pow(A, m - 1) * A;

	SquareMatrix half = pow(A, m / 2);
	return half * half;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	long long B;
	cin >> N >> B;

	SquareMatrix A(N);
	A.input();

	SquareMatrix ans = pow(A, B);
	ans.show();

	return 0;
}
