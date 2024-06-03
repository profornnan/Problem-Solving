#include <iostream>
#include <string>
using namespace std;

int W, S;
int wordCnt[128];
int strCnt[128];
string str;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> W >> S;

	for (int i = 0; i < W; ++i) {
		char ch;
		cin >> ch;
		++wordCnt[ch];
	}

	cin >> str;

	int ans = 0;
	int left = 0;
	int right = 0;

	while (right <= S) {
		const char ch = str[right];

		if (strCnt[ch] < wordCnt[ch]) {
			++strCnt[ch];
			++right;
		}
		else if (strCnt[ch] >= wordCnt[ch]) {
			--strCnt[str[left]];
			++left;
		}

		if (right - left == W)
			++ans;
	}

	cout << ans << '\n';

	return 0;
}
