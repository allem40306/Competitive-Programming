#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool go(char ch){
	if (ch >= 'A'&&ch <= 'Z')return false;
	else if (ch >= 'a'&&ch <= 'z')return false;
	else if (ch >= '0'&&ch <= '9')return false;
	return true;
}

char down(char ch){
	if (ch >= 'A'&&ch <= 'Z')return ch+32;
	return ch;
}

int main(){
	string s, ss;
	while (getline(cin, s)){
		cout << s << endl;
		bool p = 1;
		int lens = s.size();
		int i = 0, j = lens-1;
		while (i <= j){
			while (i<lens&&go(s[i]))i++;
			while (j >= 0 && go(s[j]))j--;
			if (down(s[i]) != down(s[j]))p = 0;
			i++; j--;
		}
		if (p)printf("-- is a palindrome\n");
		else printf("-- is not a palindrome\n");
	}
}