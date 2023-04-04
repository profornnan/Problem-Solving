#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

const long long MAX = 1e12;

int N;
long long DAT[10];
int zero[10];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	
	cin >> N;

	for (int k = 0; k < N; k++) {
		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++)
			DAT[str[i] - 'A'] += pow(10, str.length() - 1 - i);

		zero[str[0] - 'A'] = 1;
	}

	int cnt = 0, idx = 0;
	long long lastNum = MAX;

	for (int i = 0; i < 10; i++) {
		if (DAT[i] != 0)
			cnt++;
		if (zero[i] == 0 && lastNum > DAT[i]) {
			idx = i;
			lastNum = DAT[i];
		}
	}

	if (cnt == 10 && lastNum != MAX)
		DAT[idx] = 0;

	sort(DAT, DAT + 10, greater<long long>());

	long long ans = 0;

	for (int i = 0; i < 9; i++)
		ans += DAT[i] * (9 - i);
	
	cout << ans << '\n';

	return 0;
}
