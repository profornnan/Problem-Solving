#include <iostream>
using namespace std;

constexpr int MAX_N = 8;
constexpr int ans[MAX_N + 1]{
	-1,
	9,
	99,
	989,
	9889,
	97679,
	976679,
	9643469,
	96433469
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;
	cout << (N > MAX_N ? -1 : ans[N]) << '\n';

	return 0;
}
