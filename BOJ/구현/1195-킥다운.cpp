#include <iostream>
#include <string>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	string part1, part2;
	cin >> part1 >> part2;
	int ans = part1.size() + part2.size();
	if (part1.size() < part2.size())
		swap(part1, part2);
	for (int i = 0; i < part1.size() - part2.size() + 1; i++) {
		bool is_possible = true;
		for (int j = 0; j < part2.size(); j++) {
			if (part1[i + j] == '2' && part2[j] == '2') {
				is_possible = false;
				break;
			}
		}
		if (is_possible) {
			ans = part1.size();
			break;
		}
	}
	for (int i = 1; i < part2.size(); i++) {
		bool is_possible = true;
		for (int j = 0; j < i; j++) {
			if (part1[j] == '2' && part2[part2.size() - i + j] == '2') {
				is_possible = false;
				break;
			}
		}
		if (is_possible)
			ans = min(ans, int(part1.size() + part2.size() - i));
	}
	for (int i = 1; i < part2.size(); i++) {
		bool is_possible = true;
		for (int j = 0; j < i; j++) {
			if (part1[part1.size() - i + j] == '2' && part2[j] == '2') {
				is_possible = false;
				break;
			}
		}
		if (is_possible)
			ans = min(ans, int(part1.size() + part2.size() - i));
	}
	cout << ans << '\n';
	return 0;
}
