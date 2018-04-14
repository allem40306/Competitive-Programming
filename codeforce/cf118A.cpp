#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char is[6] = { 'a', 'o', 'y', 'e', 'u', 'i' };

bool isvowels(char s){
	for (int i = 0; i < 6; i++)
		if (s == is[i])return true;
	return false;
}

int main() {
	string s;
	while (cin >> s){
		int lens = s.size();
		for (int i = 0; i < lens; i++){
			char ch = tolower(s[i]);
			if (!isvowels(ch))cout << '.' << ch;
		}
		cout << endl;
	}
}