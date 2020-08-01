#include <iostream>
#include <algorithm>
#include <vector>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n;
vector<bool> selected(10);
vector<long long> dec_nums;

void dfs(long long num) {
	dec_nums.push_back(num);
	if (num == 0) {
		for (int i = 1; i < 10; i++) {
			selected[i] = true;
			dfs(i);
			selected[i] = false;
		}
	} else {
		for (int i = 0; i < num % 10; i++) {
			if (!selected[i]) {
				selected[i] = true;
				dfs(num * 10 + i);
				selected[i] = false;
			}
		}
	}
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n;
	dfs(0);
	sort(dec_nums.begin(), dec_nums.end());
	if (dec_nums.size() <= n)
		cout << "-1\n";
	else
		cout << dec_nums[n] << '\n';
	return 0;
}
