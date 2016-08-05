#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (cin >> s){
		int len = s.size(), i = 0, o = 2, p = 0, r = 0;
		for (; i < len; i++){
			cout << s[i];
			if (s[i] == '.'){p = 1; break; }
		}
		i++;
		if (!p)cout << '.';
		if (i < len){ r+=(s[i]-'0'); o--; i++; }
		if (i < len){ r *= 10; r += (s[i] - '0')+(i+1<len&&s[i+1]>'4'); o--; i++; }
		while (o--)r *= 10;
		if (r < 10)cout << 0;
		cout << r << endl;
	}
}