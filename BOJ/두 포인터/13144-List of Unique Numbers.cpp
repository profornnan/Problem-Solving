#include <iostream>
using namespace std;

constexpr int MAX_N = 100'000;
constexpr int MAX_M = 100'000;

int N;
int arr[MAX_N];
bool visited[MAX_M + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	long long ans = 0;
	int left = 0;

	for (int right = 0; right < N; ++right) {
		while (visited[arr[right]])
			visited[arr[left++]] = false;

		ans += (right - left + 1);
		visited[arr[right]] = true;
	}

	cout << ans << '\n';

	return 0;
}
