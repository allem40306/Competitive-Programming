#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define N 1000

int r(int x){
	return rand() % x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m, q, ti = 0;
	static string s[N][N];
	char c;
	srand(7122);
	for (cin >> t; ti < t; ti++){
		cin >> n >> m >> ws;
		for (int ni = 0; ni < n; ni++)
			for (int mi = 0; mi < m; mi++)
				cin >> s[ni][mi];
		cin >> q;
		for (int qi = 0; qi < q; qi++){
			int a, b, c, d, loc[8][2], ans = -1;
			cin >> a >> b >> c >> d;
			for (int i = 0; i < 8; i++){
				loc[i][0] = a + r(c - a + 1);
				loc[i][1] = b + r(d - b + 1);
			}
			for (int i = 0; i < 8; i++){
				int f = 0;
				for (int ai = a; ai <= c; ai++)
					for (int bi = b; bi <= d; bi++)
						if (s[ai][bi] == s[loc[i][0]][loc[i][1]])f++;
				if (f * 2 >(c - a + 1)*(d - b + 1)){
					ans = i; break;
				}
			}
			cout << (ans != -1 ? s[loc[ans][0]][loc[ans][1]] : "NO!!") << '\n';
		}
	}
}