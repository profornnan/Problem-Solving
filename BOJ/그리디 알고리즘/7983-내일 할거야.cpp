#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Task {
	int workload;
	int deadline;

	bool operator<(const Task& rhs) const {
		return deadline > rhs.deadline;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Task> tasks(N);

	for (auto& [workload, deadline] : tasks)
		cin >> workload >> deadline;

	sort(tasks.begin(), tasks.end());

	int ans = tasks[0].deadline;

	for (const auto& [workload, deadline] : tasks) {
		if (deadline < ans)
			ans = deadline;

		ans -= workload;
	}

	cout << ans << '\n';

	return 0;
}
