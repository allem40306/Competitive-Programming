#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

void oo(int& p, char ch){
	while (p--)cout << ch;
	p = 0;
	return;
}

int main(){
	string s;
	while (getline(cin, s)){
		if (s == ""){
			printf("\n");
		}
		else{
			int len = s.size(), p = 0;
			for (int i = 0; i < len; i++){
				char ch = s[i];
				if (ch >= '0'&&ch <= '9')p += int(ch - '0');
				else if (ch == '!')printf("\n");
				else if (ch == 'b')oo(p, ' ');
				else if ((ch >= 'A'&&ch <= 'Z') || ch == '*')oo(p, ch);
			}
			printf("\n");
		}	
	}
}