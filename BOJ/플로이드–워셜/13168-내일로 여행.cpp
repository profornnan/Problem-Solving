#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

constexpr double INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, R;
	cin >> N >> R;

	int cityCnt = 0;
	unordered_map<string, int> um;

	for (int i = 0; i < N; ++i) {
		string city;
		cin >> city;

		if (um.find(city) != um.end())
			continue;

		um[city] = cityCnt++;
	}

	int M;
	cin >> M;

	vector<int> path(M);

	for (int& p : path) {
		string city;
		cin >> city;

		p = um[city];
	}

	int K;
	cin >> K;

	vector<vector<double>> dist(cityCnt, vector<double>(cityCnt, INF));
	vector<vector<double>> distRail(cityCnt, vector<double>(cityCnt, INF));

	for (int i = 0; i < K; ++i) {
		string vehicle, st, en;
		double cost;

		cin >> vehicle >> st >> en >> cost;

		int u = um[st];
		int v = um[en];

		dist[u][v] = dist[v][u] = min(dist[u][v], cost);

		if (vehicle == "Mugunghwa" || vehicle == "ITX-Saemaeul" || vehicle == "ITX-Cheongchun")
			distRail[u][v] = distRail[v][u] = 0;
		else if (vehicle == "S-Train" || vehicle == "V-Train")
			distRail[u][v] = distRail[v][u] = min(distRail[u][v], cost / 2);
		else
			distRail[u][v] = distRail[v][u] = min(distRail[u][v], cost);
	}

	for (int k = 0; k < cityCnt; ++k) {
		for (int i = 0; i < cityCnt; ++i) {
			for (int j = 0; j < cityCnt; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];

				if (distRail[i][j] > distRail[i][k] + distRail[k][j])
					distRail[i][j] = distRail[i][k] + distRail[k][j];
			}
		}
	}

	double cost = 0;
	double costRail = R;

	for (int i = 0; i < M - 1; ++i) {
		int now = path[i];
		int next = path[i + 1];

		cost += dist[now][next];
		costRail += distRail[now][next];
	}

	cout << (cost > costRail ? "Yes" : "No") << '\n';

	return 0;
}
