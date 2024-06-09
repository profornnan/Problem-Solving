#include <iostream>
#include <stack>
using namespace std;

constexpr int MAX_N = 1'000'000;

struct Node {
	int idx;
	int num;
};

int N;
int nge[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	stack<Node> stk;

	for (int idx = 0; idx < N; ++idx) {
		int num;
		cin >> num;

		while (!stk.empty() && stk.top().num < num) {
			nge[stk.top().idx] = num;
			stk.pop();
		}

		stk.push({ idx, num });
	}

	for (int i = 0; i < N; ++i)
		cout << (nge[i] ? nge[i] : -1) << ' ';
	cout << '\n';

	return 0;
}
