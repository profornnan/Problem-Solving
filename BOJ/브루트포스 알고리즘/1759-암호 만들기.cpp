#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };

int L, C;
vector<char> alpha;
string path;

void dfs(int level, int last) {
	if (level >= L) {
		int vowelCnt = 0;

		for (const char& ch : path)
			for (const char& vowel : vowels)
				if (ch == vowel)
					vowelCnt++;

		if (vowelCnt >= 1 && (L - vowelCnt) >= 2)
			cout << path << '\n';
		
		return;
	}

	for (int i = last + 1; i < C; i++) {
		path.push_back(alpha[i]);
		dfs(level + 1, i);
		path.pop_back();
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> L >> C;

	vector<char>(C).swap(alpha);

	for (char& ch : alpha)
		cin >> ch;

	sort(alpha.begin(), alpha.end());

	dfs(0, -1);

	return 0;
}
