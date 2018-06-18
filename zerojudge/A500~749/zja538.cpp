#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	while (cin >> s, s != "0"){
		int x = 0;
		int len = s.size();
		for (int i = 0; i < len; i++){
			x = x * 10 + int(s[i] - '0');
			x %= 17;
		}
		if (x)cout << 0 << endl;
		else cout << 1 << endl;
	}
}

