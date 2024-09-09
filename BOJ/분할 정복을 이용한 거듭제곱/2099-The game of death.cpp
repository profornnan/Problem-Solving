#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
	int N;
	vector<vector<int>> mat;

public:
	SquareMatrix(const int& N) : N(N), mat(N, vector<int>(N)) {}

	SquareMatrix operator*(const SquareMatrix& rhs) const {
		SquareMatrix temp(N);

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < N; ++k)
					temp.mat[i][j] += mat[i][k] * rhs.mat[k][j];

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

	int N, K, M;
	cin >> N >> K >> M;

	SquareMatrix adj(N + 1);

	for (int from = 1; from <= N; ++from) {
		for (int i = 0; i < 2; ++i) {
			int to;
			cin >> to;
			adj[from][to] = 1;
		}
	}

	SquareMatrix ans = SquareMatrix::identity(N + 1);

	while (K) {
		if (K & 1)
			ans = ans * adj;

		adj = adj * adj;
		K >>= 1;
	}

	for (int i = 0; i < M; ++i) {
		int st, en;
		cin >> st >> en;
		cout << (ans[st][en] ? "death" : "life") << '\n';
	}

	return 0;
}
