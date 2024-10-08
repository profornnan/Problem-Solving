#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<string> spamAlphabet = {
	"4", "|3", "(", "|)", "3", "|=", "6", "#", "|", "_|", "|<", "|_", "|\\/|",
	"|\\|", "0", "|0", "(,)", "|?", "5", "7", "|_|", "\\/", "\\/\\/", "><", "-/", "2"
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		string plain;
		cin >> plain;

		if (plain == "end")
			break;

		string encoded;

		for (const auto& ch : plain)
			encoded += spamAlphabet[ch - 'A'];

		vector<int> dp(encoded.size() + 1);

		dp[0] = 1;

		for (int i = 1; i <= encoded.size(); ++i)
			for (const auto& spam : spamAlphabet) {
				const int S = spam.size();

				if (i - S >= 0 && spam == encoded.substr(i - S, S))
					dp[i] += dp[i - S];
			}

		cout << dp[encoded.size()] << '\n';
	}

	return 0;
}
