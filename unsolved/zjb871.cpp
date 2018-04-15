#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;
#define N 1000

int r(int x){
	return rand() % x;
}

int main() {
	int t, n, m, q, ti = 0;
	static string s[N][N], s1;
	for (cin >> t; ti < t; ti++){
		cin >> n >> m;
		static int no = 1, num[N][N] = {};
		map<string, int>ma;
		std::map<char, int>::iterator it;
		for (int ni = 0; ni < n; ni++)
			for (int mi = 0; mi < m; mi++){
			cin >> s1;
			if (!ma.count(s1))ma[s1] = no++;
			num[ni][mi] = ma[s1];
			s[ni][mi] = s1;
			}
		cin >> q;
		for (int qi = 0; qi < q; qi++){
			int a, b, c, d, loc[8][2], ans = -1;
			cin >> a >> b >> c >> d;
			for (int i = 0; i < 8; i++){
				loc[i][0] = a + r(c - a + 1);
				loc[i][1] = b + r(d - b + 1);
			}
			for (int i = 0; i < 8; i++){
				int f = 0, r = num[loc[i][0]][loc[i][1]];
				for (int ai = a; ai <= c; ai++)
					for (int bi = b; bi <= d; bi++)
						if (num[ai][bi] == r)f++;
				if (f * 2 >(c - a + 1)*(d - b + 1))ans = i;
			}
			cout << (ans != -1 ? s[loc[ans][0]][loc[ans][1]] : "NO!!") << endl;
		}
	}
}