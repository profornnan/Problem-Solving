#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int INF = 21e8;
constexpr int MAX_B = 20;

struct Bridge {
	int capacity;
	int time;
};

int B, P;
Bridge bridges[MAX_B];
int wait[MAX_B + 1];
Bridge cross[MAX_B];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		cin >> B >> P;

		if (!B && !P)
			break;

		B *= -1;

		for (int i = 0; i < B; ++i)
			cin >> bridges[i].capacity >> bridges[i].time;

		memset(wait, 0, sizeof(wait));
		memset(cross, 0, sizeof(cross));

		wait[0] = P;
		int prev = 0;

		while (wait[B] != P) {
			int now = INF;

			for (int i = 0; i < B; ++i) {
				if (wait[i] && !cross[i].capacity) {
					cross[i].capacity = min(wait[i], bridges[i].capacity);
					cross[i].time = prev + bridges[i].time;
					wait[i] -= cross[i].capacity;
				}

				if (cross[i].capacity)
					now = min(now, cross[i].time);
			}

			for (int i = 0; i < B; ++i) {
				if (cross[i].time == now) {
					wait[i + 1] += cross[i].capacity;
					cross[i].capacity = 0;
				}
			}

			prev = now;
		}

		cout << cross[B - 1].time << '\n';
	}

	return 0;
}
