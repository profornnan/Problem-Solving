#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

constexpr int MOD = 900528;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string memo, key;
	cin >> memo >> key;

	const int N = memo.size();
	unordered_map<char, int> um;

	for (const auto& ch : memo)
		if (um.find(ch) == um.end())
			um.insert({ ch, um.size() + 1 });

	int ans = 0;

	for (const auto& ch : key) {
		ans *= N;
		ans += um[ch];
		ans %= MOD;
	}

	cout << ans << '\n';

	return 0;
}
