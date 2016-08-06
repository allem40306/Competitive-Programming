#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (cin >> s){
		int i = 0, j = 0;
		while (1){
			if (s[i] == '.')break;
			i++;
		}
		while (s.size() <= i + 3)s += '0';
		if (s[i+3] >= '5')s[i+2]++;
		if (s[i+2] > '9')s[i+1]++, s[i+2] = '0';
		if (s[i + 1] > '9')s[i - 1]++, s[i + 1] = '0';
		s = s.substr(0, i + 3);
		if (s == "-0.00") s = "0.00";
		cout << s<< endl;
	}
}