#include <iostream>
#include <string>
using namespace std;

int main(){
	int i, t;
	for (cin >> t, i = 0; i < t; i++){
		string s;
		cin >> s;
		int len, j, k;
		for (j =0, k = 1, len = s.size(); k < len; k++){
			if (s[j] == s[k])j++;
		}
		if (len % (k - j))printf("%d\n", len);
		else printf("%d\n", k - j);
	}
}