#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

int n, m;
map<string, vector<string> > adj;
map<string, double> blood;

void dfs(string now, int cnt) {
	blood[now] += pow(0.5, cnt);
	for (int i = 0; i < adj[now].size(); i++)
		dfs(adj[now][i], cnt + 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	string start, c, p1, p2;
	cin >> start;
	for (int i = 0; i < n; i++) {
		cin >> c >> p1 >> p2;
		adj[p1].push_back(c);
		adj[p2].push_back(c);
	}
	dfs(start, 0);
	string ans;
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (blood[c] > blood[ans]) ans = c;
	}
	cout << ans << '\n';
	return 0;
}
