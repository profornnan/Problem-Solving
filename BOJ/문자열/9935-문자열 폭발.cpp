#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str, word;
	cin >> str >> word;

	string res = "";
	const int wordSize = static_cast<int>(word.size());

	for (const auto& ch : str) {
		res.push_back(ch);

		const int resSize = static_cast<int>(res.size());
		const int diff = resSize - wordSize;

		if (diff < 0)
			continue;

		if (res.back() != word.back())
			continue;

		bool isSame = true;

		for (int i = 0; i < wordSize; ++i)
			if (res[diff + i] != word[i])
				isSame = false;

		if (!isSame)
			continue;

		for (int i = 0; i < wordSize; ++i)
			res.pop_back();
	}

	if (res.empty())
		res = "FRULA";

	cout << res << '\n';

	return 0;
}
