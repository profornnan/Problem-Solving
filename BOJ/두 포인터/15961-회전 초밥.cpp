#include <iostream>
#include <deque>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int n, d, k, c;
int sushi[3000000];
int sushi_type[3000 + 1];
int answer;
deque<int> dq;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
		cin >> sushi[i];

	int cnt = 0;

	for (int i = 0; i < k; i++) {
		dq.push_back(sushi[i]);

		if (!sushi_type[sushi[i]]++)
			cnt++;

		answer = answer > cnt ? answer : cnt;
	}

	for (int i = 0; i < n - 1; i++) {

		dq.pop_front();

		if (!(--sushi_type[sushi[i]]))
			cnt--;

		dq.push_back(sushi[(i + k) % n]);

		if (!sushi_type[sushi[(i + k) % n]]++)
			cnt++;
		
		if (sushi_type[c])
			answer = answer > cnt ? answer : cnt;
		else
			answer = answer > cnt + 1 ? answer : cnt + 1;
	}

	cout << answer << '\n';

	return 0;
}
