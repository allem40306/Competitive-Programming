#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)){
		int i, c, maxc = 0;
		for (i = 0; i != s.size(); i++){
			if (s[i] == ' ') maxc = max(++c, maxc);
			else c = 0;
		}
		cout << ceil(log2(maxc)) << endl;
	}
}