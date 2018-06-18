#include <iostream>
#include <string>
using namespace std;

int main(){
	string s, r[4] = { "WEAK\n", "ACCEPTABLE\n", "GOOD\n", "STRONG\n" };
	bool b[3];
	int ans, len, i;
	while (cin >> s){
		len = s.size();
		b[0] = b[1] = b[2] = 0;
		for (i = 0; i<len; i++){
			if (s[i] >= 'A'&&s[i] <= 'Z')b[0] = 1;
			else if (s[i] >= 'a'&&s[i] <= 'z')b[1] = 1;
			else b[2] = 1;
		}
		printf("This password is "), cout << r[(b[0] && b[1]) + ((b[0]||b[1])&&b[2]) + (len >= 8)];
	}
}
