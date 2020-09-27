#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int T, N;
vector<pair<int, int> > points;
vector<int> start_point_set;
double min_vector_sum = numeric_limits<double>::max();

void solution(int cnt, int last) {
	if (cnt == N / 2) {
		vector<int> end_point_set;

		for (int i = 0; i < N; i++)
			if (find(start_point_set.begin(), start_point_set.end(), i) == start_point_set.end())
				end_point_set.push_back(i);

		int x = 0, y = 0;

		for (int i = 0; i < N / 2; i++) {
			pair<int, int> s_point = points[start_point_set[i]];
			pair<int, int> e_point = points[end_point_set[i]];
			x += s_point.first - e_point.first;
			y += s_point.second - e_point.second;
		}

		double vector_sum = sqrt(pow(x, 2) + pow(y, 2));
		min_vector_sum = min_vector_sum < vector_sum ? min_vector_sum : vector_sum;
		return;
	}

	for (int i = last + 1; i < points.size(); i++) {
		start_point_set.push_back(i);
		solution(cnt + 1, i);
		start_point_set.pop_back();

		if (cnt == 0)
			break;
	}
}

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);
	cout.precision(12);
	cout << fixed;
	cin >> T;
	while (T--) {
		cin >> N;
		points = vector<pair<int, int> >(N);
		min_vector_sum = numeric_limits<double>::max();
		for (int i = 0; i < N; i++)
			cin >> points[i].first >> points[i].second;
		solution(0, -1);
		cout << min_vector_sum << '\n';
	}
	return 0;
}
