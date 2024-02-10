#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int L;
	string P;

	cin >> L >> P;

	vector<int> pi(L);
	int j = 0;

	for (int i = 1; i < L; ++i) {
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}

	cout << L - pi[L - 1] << '\n';

	return 0;
}
