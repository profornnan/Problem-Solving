#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Problem {
	int deadline;
	int score;

	bool operator<(const Problem& rhs) const {
		if (deadline < rhs.deadline)
			return false;
		if (deadline > rhs.deadline)
			return true;
		return score < rhs.score;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	priority_queue<Problem> problemPq;
	priority_queue<int, vector<int>, greater<int>> scorePq;

	for (int i = 0; i < N; ++i) {
		int deadline, score;
		cin >> deadline >> score;
		problemPq.push({ deadline, score });
	}

	int now = 0;
	int ans = 0;

	while (!problemPq.empty()) {
		int score = problemPq.top().score;
		problemPq.pop();

		ans += score;
		scorePq.push(score);

		++now;

		while (!problemPq.empty() && problemPq.top().deadline <= now) {
			int score = problemPq.top().score;
			problemPq.pop();

			if (score <= scorePq.top())
				continue;

			ans -= scorePq.top();
			scorePq.pop();

			ans += score;
			scorePq.push(score);
		}
	}

	cout << ans << '\n';

	return 0;
}
