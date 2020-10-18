#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int N, M, fuel;
int board[22][22];
int dist[22][22];

struct Taxi {
	int y, x, fuel;
};

struct Client {
	int client_num, start_y, start_x, end_y, end_x;
};

Taxi taxi;
map<int, Client> clients;

void set_client_on_board() {
	for (auto client_info : clients) {
		Client client = client_info.second;
		board[client.start_y][client.start_x] = client.client_num;
	}
}

void delete_client_from_board() {
	for (auto client_info : clients) {
		Client client = client_info.second;
		board[client.start_y][client.start_x] = 0;
	}
}

int simulation() {
	while (clients.size()) {
		//go to client
		set_client_on_board();

		vector<pair<int, int> > client_pos;
		memset(dist, -1, sizeof(dist));
		queue<pair<int, int> > q;
		int min_dist = -1;
		q.push(make_pair(taxi.y, taxi.x));
		dist[taxi.y][taxi.x] = 0;

		while (!q.empty()) {
			int q_size = q.size();
			for (int i = 0; i < q_size; i++) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				if (board[y][x] != 0) {
					client_pos.push_back(make_pair(y, x));
					min_dist = dist[y][x];
				}
				for (int dir = 0; dir < 4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (board[ny][nx] == -1 || dist[ny][nx] != -1) continue;
					q.push(make_pair(ny, nx));
					dist[ny][nx] = dist[y][x] + 1;
				}
			}
			if (client_pos.size())
				break;
		}

		if (min_dist > taxi.fuel || min_dist == -1) return -1;

		sort(client_pos.begin(), client_pos.end());
		pair<int, int> pos = client_pos[0];
		int client_num = board[pos.first][pos.second];

		Client client = clients[client_num];

		taxi.y = client.start_y;
		taxi.x = client.start_x;
		taxi.fuel -= min_dist;

		delete_client_from_board();

		//go to destination
		memset(dist, -1, sizeof(dist));
		q = queue<pair<int, int> >();
		min_dist = -1;
		q.push(make_pair(taxi.y, taxi.x));
		dist[taxi.y][taxi.x] = 0;

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (y == client.end_y && x == client.end_x) {
				min_dist = dist[y][x];
				break;
			}
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (board[ny][nx] == -1 || dist[ny][nx] != -1) continue;
				q.push(make_pair(ny, nx));
				dist[ny][nx] = dist[y][x] + 1;
			}
		}

		if (min_dist > taxi.fuel || min_dist == -1) return -1;

		taxi.y = client.end_y;
		taxi.x = client.end_x;
		taxi.fuel += min_dist;

		clients.erase(client_num);
	}

	return taxi.fuel;
}

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> taxi.fuel;

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> board[y][x];
			if (board[y][x]) board[y][x] = -1;
		}
	}

	for (int y = 0; y <= N + 1; y++)
		board[y][0] = board[y][N + 1] = -1;

	for (int x = 0; x <= N + 1; x++)
		board[0][x] = board[N + 1][x] = -1;

	cin >> taxi.y >> taxi.x;

	for (int client_num = 1; client_num <= M; client_num++) {
		Client client;
		client.client_num = client_num;
		cin >> client.start_y >> client.start_x >> client.end_y >> client.end_x;
		clients[client_num] = client;
	}

	cout << simulation() << '\n';

	return 0;
}
