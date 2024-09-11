#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	vector<string> words;
	vector<string> prefixes;

	while (cin >> str)
		words.emplace_back(str);

	for (const auto& word : words) {
		while (!prefixes.empty() && (prefixes.back().length() >= word.length() || prefixes.back() != word.substr(0, prefixes.back().length())))
			prefixes.pop_back();

		for (const auto& prefix : prefixes) {
			if (binary_search(words.begin(), words.end(), word.substr(prefix.length()))) {
				cout << word << '\n';
				break;
			}
		}

		prefixes.emplace_back(word);
	}

	return 0;
}
