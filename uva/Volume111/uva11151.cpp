#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define S 1005

int main() {
	int t = 0;
	string s;
	getline(cin, s);
	for (int a = 0; s[a]; a++){
		t = t * 10 + int(s[a] - '0');
	}
	while (t--) {
		char s1[S], s2[S];
		getline(cin, s);
		if (s == ""){
			cout << "0" << endl;
			continue;
		}
		int len = s.size();
		for (int i = 0; i < len; i++){
			s1[i] = s[i];
			s2[i] = s
				[len - i - 1];
		}
		static int lcs[S][S] = {};
		for (int a = 1; a <= len; a++)
			for (int b = 1; b <= len; b++) {
			if (s1[a - 1] == s2[b - 1])
				lcs[a][b] = lcs[a - 1][b - 1] + 1;
			else
				lcs[a][b] = max(lcs[a - 1][b], lcs[a][b - 1]);
			}
		cout << lcs[len][len] << endl;
	}
}