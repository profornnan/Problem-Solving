#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<string> arr(N);

	for (auto& str : arr)
		cin >> str;

	sort(arr.begin(), arr.end(), [](const string& lhs, const string& rhs) {
		return lhs + rhs > rhs + lhs;
	});

	for (const auto& str : arr)
		cout << str << ' ';
	cout << '\n';

	return 0;
}
