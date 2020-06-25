#include <iostream>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

struct Data {
	int time;
	int emoticon;
	int clipboard;
};

bool visited[1001][1001];

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	int s;
	cin >> s;
	queue<Data> q;
	q.push({ 0, 1, 0 });
	visited[1][0] = true;
	while (!q.empty()) {
		Data now = q.front();
		q.pop();
		if (now.emoticon == s) {
			cout << now.time << '\n';
			return 0;
		}
		if (!visited[now.emoticon][now.emoticon]) {
			q.push({ now.time + 1, now.emoticon, now.emoticon });
			visited[now.emoticon][now.emoticon] = true;
		}
		if (now.emoticon + now.clipboard <= 1000) {
			if (!visited[now.emoticon + now.clipboard][now.clipboard]) {
				q.push({ now.time + 1, now.emoticon + now.clipboard, now.clipboard });
				visited[now.emoticon + now.clipboard][now.clipboard] = true;
			}
		}
		if (now.emoticon - 1 > 0) {
			if (!visited[now.emoticon - 1][now.clipboard]) {
				q.push({ now.time + 1, now.emoticon - 1, now.clipboard });
				visited[now.emoticon - 1][now.clipboard] = true;
			}
		}
	}
	return 0;
}
