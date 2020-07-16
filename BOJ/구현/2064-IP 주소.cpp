#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n;
vector<string> ip_bin_arr;

string dec2bin(string str) {
	int n = stoi(str);
	string ret;
	while (n) {
		ret += to_string(n % 2);
		n /= 2;
	}
	while (ret.size() < 8)
		ret += '0';
	reverse(ret.begin(), ret.end());
	return ret;
}

string bin2dec(string str) {
	string ret;
	for (int i = 0; i < str.size(); i += 8) {
		int n = 0;
		string bin = str.substr(i, 8);
		for (int j = 0; j < bin.size(); j++)
			n += (bin[j] - '0') * pow(2, 7 - j);
		ret += to_string(n) + '.';
	}
	ret.pop_back();
	return ret;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ip[16];
		cin >> ip;
		string ip_bin;
		char* ptr = strtok(ip, ".");
		while (ptr != NULL) {
			ip_bin += dec2bin(string(ptr));
			ptr = strtok(NULL, ".");
		}
		ip_bin_arr.push_back(ip_bin);
	}
	string network_addr, network_mask;
	for (int i = 0; i < ip_bin_arr[0].size(); i++) {
		char now = ip_bin_arr[0][i];
		bool is_correct = true;
		for (string ip_bin : ip_bin_arr) {
			if (now != ip_bin[i]) {
				is_correct = false;
				break;
			}
		}
		if (!is_correct)
			break;
		network_addr += now;
		network_mask += "1";
	}
	while (network_addr.size() < 32) {
		network_addr += "0";
		network_mask += "0";
	}
	cout << bin2dec(network_addr) << '\n';
	cout << bin2dec(network_mask) << '\n';
	return 0;
}
