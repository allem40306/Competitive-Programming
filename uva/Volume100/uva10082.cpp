//10082 - WERTYU (by Snail)
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, k = "  `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	int i;
	while (getline(cin, s)) {
		for (i = 0; i != s.size(); i++)
			cout << k[k.find(s[i], 1) - 1];
		cout << endl;
	}
}