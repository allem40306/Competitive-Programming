#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define S 1002

int main() {
	string s1, s2;
	int  cas = 0;
	while (getline(cin,s1)) {
		getline(cin, s2);
		int n1 = s1.size(), n2 = s2.size();
		static int lcs[S][S] = {};
		for (int a = 1; a <= n1; a++)
			for (int b = 1; b <= n2; b++) {
			if (s1[a - 1] == s2[b - 1])
				lcs[a][b] = lcs[a - 1][b - 1] + 1;
			else
				lcs[a][b] = max(lcs[a - 1][b], lcs[a][b - 1]);
			}
		cout << lcs[n1][n2] << endl;
	}
}