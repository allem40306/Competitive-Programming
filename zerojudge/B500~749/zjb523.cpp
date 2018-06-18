#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	string  s1, s[500];
	int len = 0, type = 0;
	while (getline(cin, s1)){
		int flag = 1;
		len++;
		for (int i = 0; i < len; i++){
			if (s[i] == s1){
				cout << "YES\n"; flag--; break;
			}
		}
		if (flag){
			cout << "NO\n";
			s[type++] = s1;
		}
	}
}