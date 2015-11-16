#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int main(){
	int nw, i;
	string  s;
	while (getline(cin, s)){
		nw = 1;
		for (i = 1; i != s.size(); i++){
			if (isalpha(s[i]) && !isalpha(s[i - 1]))nw++;
		}
		cout << nw << endl;
	}
}
