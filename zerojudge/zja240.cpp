#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int m, n,sum;
	string s = "70588235294117647";
	cin >> m;
	while (m--){
		cin >> n;
		cout << s[n % 16] << " ";
		sum = 72 * (n / 16);
		for (int i = n % 16; i >= 1; i--)
			sum += s[i] - '0';
		cout << sum << endl;
	}
}