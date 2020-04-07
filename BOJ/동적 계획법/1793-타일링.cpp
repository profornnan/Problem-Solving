#include <iostream>
#include <string>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

string d[251];

string add_big_num(string num1, string num2) {
	int sum = 0;
	string result;
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	int n;
	d[0] = d[1] = "1";
	for (int i = 2; i <= 250; i++)
		d[i] = add_big_num(d[i - 1], add_big_num(d[i - 2], d[i - 2]));
	while (cin >> n)
		cout << d[n] << '\n';
	return 0;
}
