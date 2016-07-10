#include <iostream>
#include <string>
using namespace std;
#define N 10005

int main(){
	string s;
	while (cin >> s,s!="0"){
		int a = 0, b = 0, lens = s.size();
		for (int i = 0; i < lens; i++){
			if (i % 2)a += int(s[i] - '0');
			else b += int(s[i] - '0');
		}
		cout << s;
		if (a%11 == b%11)printf(" is a multiple of 11.\n");
		else printf(" is not a multiple of 11.\n");
	}
}