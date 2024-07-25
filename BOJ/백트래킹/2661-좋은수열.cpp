#include <iostream>
#include <string>
using namespace std;

int N;
string path;
bool printed;

bool isValid() {
	const int pathLen = path.size();

	for (int subLen = 1; subLen <= pathLen / 2; ++subLen)
		if (path.substr(pathLen - subLen * 2, subLen) == path.substr(pathLen - subLen, subLen))
			return false;

	return true;
}

void dfs() {
	if (printed)
		return;

	if (path.size() >= N) {
		cout << path << '\n';
		printed = true;
		return;
	}

	for (int i = 1; i <= 3; ++i) {
		path.push_back('0' + i);
		if (isValid()) dfs();
		path.pop_back();
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	dfs();

	return 0;
}
