#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const int INF = 987654321;
int N, P;
int cost[16][16];
string init_state;
int d[1 << 16];  // 1 : Y, 0 : N

int bit_count(int x) {
	if (x == 0) return 0;
	return x % 2 + bit_count(x / 2);
}

int calc_min_cost(int state) {
	if (d[state] != -1)
		return d[state];

	if (bit_count(state) >= P)
		return 0;

	int &ret = d[state];
	ret = INF;

	for (int i = 0; i < N; i++) {
		if ((state & (1 << i)) == 0) {
			int n_cost = INF;

			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if((state & (1 << j)))
					n_cost = min(n_cost, cost[j][i]);
			}

			n_cost += calc_min_cost(state | (1 << i));
			ret = min(ret, n_cost);
		}
	}

	if (ret > INF)
		ret = INF;

	return ret;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];
	cin >> init_state;
	cin >> P;

	memset(d, -1, sizeof(d));
	int state = 0;

	for (int i = 0; i < init_state.size(); i++)
		if (init_state[i] == 'Y')
			state |= (1 << i);

	int min_cost = calc_min_cost(state);

	if (min_cost == INF)
		min_cost = -1;

	cout << min_cost << '\n';

	return 0;
}
