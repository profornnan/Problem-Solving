#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(const string& P) {
	const int M = static_cast<int>(P.size());
	vector<int> pi(M);
	int j = 0;

	for (int i = 1; i < M; ++i) {
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}

	return pi;
}

vector<int> kmp(const string& T, const string& P) {
	const int N = static_cast<int>(T.size());
	const int M = static_cast<int>(P.size());
	vector<int> ret;
	vector<int> pi = getPi(P);
	int j = 0;

	for (int i = 0; i < N; ++i) {
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j]) {
			if (j == M - 1) {
				ret.push_back(i - M + 1);
				j = pi[j];
			}
			else {
				++j;
			}
		}
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string T, P;

	getline(cin, T);
	getline(cin, P);

	vector<int> ans = kmp(T, P);

	cout << ans.size() << '\n';

	for (const auto& idx : ans)
		cout << idx + 1 << ' ';
	cout << '\n';

	return 0;
}
