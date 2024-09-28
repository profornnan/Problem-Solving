#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	long long A, B;
	cin >> A >> B;

	long long D = 2;
	const long long L = sqrt(max(A, B));

	while (D <= L) {
		if (A == B) {
			cout << A << '\n';
			return 0;
		}

		if (A < B)
			swap(A, B);

		if (A % D == 0)
			A /= D;
		else if (B % D == 0)
			B /= D;
		else
			++D;
	}

	cout << "1\n";

	return 0;
}
