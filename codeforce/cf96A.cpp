#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	while (cin >> s){
		bool d = false;
		int i = 1, j = 1, len = s.size();
		for (; i < len; i++){
			if (s[i] == s[i - 1])j++;
			else j = 1;
			if (j >= 7)d = true;;
		}
		printf("%s\n", d ? "YES": "NO");
	}
}