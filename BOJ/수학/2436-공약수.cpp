#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GCD, LCM;
int A, B;
vector<int> num;

void dfs(int level, int a, int b) {
	if (level >= num.size()) {
		if (a > b)
			swap(a, b);

		if (B - A > b - a) {
			B = b;
			A = a;
		}

		return;
	}

	dfs(level + 1, a * num[level], b);
	dfs(level + 1, a, b * num[level]);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> GCD >> LCM;

	int remain = LCM / GCD;
	int div = 2;

	while (remain != 1) {
		if (remain % div == 0) {
			num.push_back(1);

			while (remain % div == 0) {
				num.back() *= div;
				remain /= div;
			}
		}

		++div;
	}

	A = 1;
	B = LCM / GCD;

	if (!num.empty())
		dfs(1, 1, num[0]);

	cout << A * GCD << ' ' << B * GCD << '\n';

	return 0;
}
