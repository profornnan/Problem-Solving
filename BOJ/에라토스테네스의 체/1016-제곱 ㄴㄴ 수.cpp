#include <iostream>
#include <cmath>
#include <vector>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);

	long long min_num, max_num, num = 2;

	cin >> min_num >> max_num;

	vector<bool> sieve(max_num - min_num + 1, false);

	while (true) {
		long long square_num = pow(num, 2);

		if (square_num > max_num)
			break;

		long long current_num = (min_num / square_num) * square_num;
		
		if (current_num < min_num)
			current_num += square_num;

		while (current_num <= max_num) {
			sieve[current_num - min_num] = true;
			current_num += square_num;
		}

		num++;
	}

	int ans = 0;

	for (int i = 0; i < sieve.size(); i++)
		if (sieve[i] == false)
			ans++;

	cout << ans << '\n';

	return 0;
}
