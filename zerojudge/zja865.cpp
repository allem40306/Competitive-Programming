#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
char fi[27] = { 'A', 'B', 'G', 'D', 'E', '#', 'Z', 'Y', 'H', 'I', 'K', 'L', 'M', 'N', 'X','O', 'P', 'Q', 'R', 'S', 'T', 'U', 'F', 'C', '$', 'W' };

int f(char a){
	for (int i = 0; i < 27; i++)
		if (a == fi[i])return i + 1;
	return 27;
}

int g(int i){
	int r = 1;
	while (i--)r *= 10;
	return r;
}

int main(){
	string s;
	while (cin >> s, s != "."){
		int ans = 0;
		for (int i = 0, len = s.size(); i < len; i++){
			int pos = f(s[i]);
			ans += (pos % 9 + 9 * (pos % 9 == 0))*g((pos-1) / 9);
		}
		cout << ans << endl;
	}
}