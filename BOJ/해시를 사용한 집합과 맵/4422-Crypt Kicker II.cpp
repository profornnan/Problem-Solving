#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const string CLUE = "the quick brown fox jumps over the lazy dog";

char replacements['z' - 'a' + 1];

bool isValid(const string& str) {
	if (str.size() != CLUE.size())
		return false;

	for (int i = 0; i < str.size(); ++i)
		if ((str[i] == ' ') ^ (CLUE[i] == ' '))
			return false;

	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	vector<string> strs;

	while (getline(cin, str))
		strs.emplace_back(str);

	for (auto& str : strs) {
		if (!isValid(str))
			continue;

		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == ' ')
				continue;

			auto& replacement = replacements[str[i] - 'a'];

			if (!replacement)
				replacement = CLUE[i];
			else if (replacement != CLUE[i]) {
				memset(replacements, 0, sizeof(replacements));
				break;
			}
		}
	}

	for (auto& str : strs) {
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == ' ')
				continue;

			auto& replacement = replacements[str[i] - 'a'];

			if (!replacement) {
				cout << "No solution.\n";
				return 0;
			}

			str[i] = replacement;
		}
	}

	for (const auto& str : strs)
		cout << str << '\n';

	return 0;
}
