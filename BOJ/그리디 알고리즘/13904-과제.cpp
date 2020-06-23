#include <iostream>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	int n, d, w;
	priority_queue<pair<int, int> > day_score;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		day_score.push({ d, w });
	}
	int day = day_score.top().first;
	priority_queue<int> pq;
	int score = 0;
	while (day) {
		if (!day_score.empty()) {
			while (day_score.top().first == day) {
				pq.push(day_score.top().second);
				day_score.pop();
				if (day_score.empty())
					break;
			}
		}
		if (!pq.empty()) {
			score += pq.top();
			pq.pop();
		}
		day--;
	}
	cout << score << '\n';
	return 0;
}
