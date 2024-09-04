#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

constexpr int INF = 21e8;
constexpr int NUM_SIZE = 10;

const vector<pair<char, int>> spelling[NUM_SIZE] = {
	{{'Z', 1}, {'E', 1}, {'R', 1}, {'O', 1}},
	{{'T', 1}, {'W', 1}, {'O', 1}},
	{{'F', 1}, {'O', 1}, {'U', 1}, {'R', 1}},
	{{'S', 1}, {'I', 1}, {'X', 1}},
	{{'E', 1}, {'I', 1}, {'G', 1}, {'H', 1}, {'T', 1}},
	{{'O', 1}, {'N', 1}, {'E', 1}},
	{{'T', 1}, {'H', 1}, {'R', 1}, {'E', 2}},
	{{'F', 1}, {'I', 1}, {'V', 1}, {'E', 1}},
	{{'S', 1}, {'E', 2}, {'V', 1}, {'N', 1}},
	{{'N', 2}, {'I', 1}, {'E', 1}}
};

constexpr int idx2num[NUM_SIZE] = {
	0,
	2,
	4,
	6,
	8,
	1,
	3,
	5,
	7,
	9
};

int cnts['Z' - 'A' + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << ": ";

		string str;
		cin >> str;

		for (const auto& ch : str)
			++cnts[ch - 'A'];

		vector<int> ans;

		for (int i = 0; i < NUM_SIZE; ++i) {
			int minCnt = INF;

			for (const auto& [ch, cnt] : spelling[i])
				minCnt = min(minCnt, cnts[ch - 'A'] / cnt);

			if (!minCnt)
				continue;

			for (const auto& [ch, cnt] : spelling[i])
				cnts[ch - 'A'] -= minCnt * cnt;

			ans.insert(ans.end(), minCnt, idx2num[i]);
		}

		sort(ans.begin(), ans.end());

		for (const auto& num : ans)
			cout << num;

		cout << '\n';
	}

	return 0;
}
