#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 10

int zz(string s){
	int z = 0, lens = s.size();
	for (int i = 0; i < lens; i++)
		z += (s[i] == '0');
	return z;
}

int main() {
	string s;
	while (getline(cin, s),s!="~"){
		int stop = 0;
		string a, b = "";
		do{
			stringstream ss(s);
			int flag;
			while (ss >> a){
				if (a == "#"){ stop = 1; break; }
				int lena =a.size();
				if (lena == 1)flag = 1;
				else if (lena == 2)flag = 0;
				else for (int i = 2; i < lena; i++)b += ('0' + flag);
			}
			if (stop)break;
		} while (getline(cin, s));
		int ans = 0, lenb = b.size();
		for (int i = 0; i < lenb; i++){
			ans *= 2;
			ans += (b[i] - '0');
		}
		printf("%d\n", ans);
	}
}