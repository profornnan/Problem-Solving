#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Canvas {
	int st;
	int en;
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Canvas> canvases(N);
	vector<int> cnts(N);

	for (auto& [st, en] : canvases)
		cin >> st >> en;

	int P;
	cin >> P;

	vector<int> pegs(P);
	int canvasIdx = 0;

	for (auto& peg : pegs) {
		cin >> peg;

		while (canvasIdx < N) {
			const auto& [st, en] = canvases[canvasIdx];

			if (peg < st) {
				break;
			}
			else if (st <= peg && peg < en) {
				++cnts[canvasIdx];
				break;
			}
			else if (peg == en) {
				++cnts[canvasIdx];
				++canvasIdx;
			}
			else if (en < peg) {
				++canvasIdx;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		if (cnts[i] > 2) {
			cout << "impossible\n";
			return 0;
		}
	}

	vector<int> ans;

	for (int i = 1; i < N; ++i) {
		if (canvases[i - 1].en != canvases[i].st)
			continue;

		if (cnts[i - 1] >= 2 || cnts[i] >= 2)
			continue;

		const int& peg = canvases[i].st;

		if (binary_search(pegs.begin(), pegs.end(), peg))
			continue;

		ans.push_back(peg);
		++cnts[i - 1];
		++cnts[i];
	}

	for (int i = 0; i < N; ++i) {
		int peg = canvases[i].st + 1;

		while (cnts[i] < 2) {
			if (binary_search(pegs.begin(), pegs.end(), peg)) {
				++peg;
				continue;
			}

			ans.push_back(peg);
			++cnts[i];
			++peg;
		}
	}

	cout << ans.size() << '\n';

	for (const auto& peg : ans)
		cout << peg << ' ';
	cout << '\n';

	return 0;
}
