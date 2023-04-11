#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 21e8;

int N, S;
int num[100000];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	int left = 0;
	int right = 0;

	int sum = 0;
	int ans = MAX;

	while (left <= N && right <= N) {
		if (sum >= S) {
			ans = min(ans, right - left);
			sum -= num[left];
			left++;
		}
		else {
			sum += num[right];
			right++;
		}
	}

	if (ans == MAX)
		ans = 0;

	cout << ans << '\n';

	return 0;
}
