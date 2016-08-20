#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define S 102

int main() {
	string s1, s2, s3;
	int  cas = 0;
	while (cin >> s1 >> s2>>s3) {
		int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
		static int lcs[S][S][S] = {};
		for (int a = 1; a <= n1; a++)
			for (int b = 1; b <= n2; b++)
				for (int c = 1; c <= n3; c++){
			if (s1[a-1] == s2[b-1] && s2[b-1] == s3[c-1])
				lcs[a][b][c] = lcs[a - 1][b - 1][c - 1] + 1;
			else
				lcs[a][b][c] = max(lcs[a][b][c - 1], max(lcs[a - 1][b][c], lcs[a][b - 1][c]));
			}
		cout << lcs[n1][n2][n3] << endl;
	}
}