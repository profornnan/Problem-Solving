#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	cin >> str;

	int ans = 0;

	for (int st = 0; st < str.size(); ++st) {
		int j = 0;
		vector<int> pi(str.size() - st);

		for (int i = 1; i < str.size() - st; ++i) {
			while (j > 0 && str[st + i] != str[st + j])
				j = pi[j - 1];
			if (str[st + i] == str[st + j]) {
				pi[i] = ++j;
				ans = ans > pi[i] ? ans : pi[i];
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
