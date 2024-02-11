#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_L = 50;

int N;
string str;
vector<string> words;
vector<string> sortedWords;
int dp[MAX_L];

int dfs(int idx) {
	if (idx == str.size())
		return 0;

	int& ret = dp[idx];

	if (ret != -1)
		return ret;

	ret = INF;

	for (int k = 0; k < N; ++k) {
		const string& word = words[k];

		if (idx + word.size() > str.size())
			continue;

		string sub = str.substr(idx, word.size());
		sort(sub.begin(), sub.end());

		if (sub != sortedWords[k])
			continue;

		int diff = 0;

		for (int i = 0; i < word.size(); ++i)
			if (str[idx + i] != word[i])
				++diff;

		ret = min(ret, diff + dfs(idx + word.size()));
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> str >> N;

	memset(dp, -1, sizeof(dp));
	words.resize(N);

	for (auto& word : words) {
		cin >> word;
		sortedWords.push_back(word);
		sort(sortedWords.back().begin(), sortedWords.back().end());
	}

	cout << (dfs(0) == INF ? -1 : dfs(0)) << '\n';

	return 0;
}
