#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n;
vector<string> plate(5);
vector<vector<int> > possible_nums;
double avg;

const vector<vector<string> > numbers = {
	{
		"###",
		"#.#",
		"#.#",
		"#.#",
		"###"
	},
	{
		"..#",
		"..#",
		"..#",
		"..#",
		"..#"
	},
	{
		"###",
		"..#",
		"###",
		"#..",
		"###"
	},
	{
		"###",
		"..#",
		"###",
		"..#",
		"###"
	},
	{
		"#.#",
		"#.#",
		"###",
		"..#",
		"..#"
	},
	{
		"###",
		"#..",
		"###",
		"..#",
		"###"
	},
	{
		"###",
		"#..",
		"###",
		"#.#",
		"###"
	},
	{
		"###",
		"..#",
		"..#",
		"..#",
		"..#"
	},
	{
		"###",
		"#.#",
		"###",
		"#.#",
		"###"
	},
	{
		"###",
		"#.#",
		"###",
		"..#",
		"###"
	}
};

int main(void)
{
	sws;

	freopen("input.txt", "r", stdin);

	cout << fixed;
	cout.precision(7);
	cin >> n;
	possible_nums = vector<vector<int> >(n);

	for (int i = 0; i < plate.size(); i++)
		cin >> plate[i];

	for (int i = 0; i < n; i++) {
		int x_offset = 4 * i;

		for (int num = 0; num < numbers.size(); num++) {
			bool is_fit = true;

			for (int y = 0; y < 5; y++) {

				for (int x = 0; x < 3; x++) {

					if (plate[y][x_offset + x] == '#' && numbers[num][y][x] == '.') {
						is_fit = false;
						break;
					}
				}
			}

			if (is_fit)
				possible_nums[i].push_back(num);
		}

		if (possible_nums[i].size() == 0) {
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 0; i < possible_nums.size(); i++) {
		int sum = 0;
		for (int num : possible_nums[i]) {
			sum += num;
		}
		avg += (double)sum / possible_nums[i].size() * pow(10, n - i - 1);
	}

	cout << avg << '\n';

	return 0;
}
