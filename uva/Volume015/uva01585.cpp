#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int t;
	string s;
	cin >> t;
	while (t-- ){
		int ans = 0, plus = 0;
		cin >> s;
		int len = s.size();
		for (int i = 0; i < len; i++){
			if (s[i] == 'O')plus++;
			else plus = 0;
			ans += plus;
		}
		printf("%d\n", ans);
	}
}