#include <iostream>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_H = 50;
constexpr int MAX_W = 50;

int T, H, W, M;
string str;
int psum[MAX_H + 1][MAX_W + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> H >> W >> M >> str;

		memset(psum, 0, sizeof(psum));

		for (int y = 1; y <= H; ++y) {
			for (int x = 1; x <= W; ++x) {
				char ch;
				cin >> ch;
				psum[y][x] = psum[y - 1][x] + psum[y][x - 1] - psum[y - 1][x - 1] + (str.find(ch) != string::npos ? 1 : 0);
			}
		}

		int numer = 0;
		int denom = 0;

		for (int y = 1; y <= H; ++y) {
			for (int x = 1; x <= W; ++x) {
				for (int r = M; r <= H - y + 1; ++r) {
					for (int c = M; c <= W - x + 1; ++c) {
						const int water = psum[y + r - 1][x + c - 1] - psum[y + r - 1][x - 1] - psum[y - 1][x + c - 1] + psum[y - 1][x - 1];
						const int left = numer * r * c;
						const int right = water * denom;

						if (left < right || (left == right && (r * c) > denom)) {
							numer = water;
							denom = r * c;
						}
					}
				}
			}
		}

		cout << "Data Set " << tc << ":\n" << numer << "/" << denom << "\n\n";
	}

	return 0;
}
