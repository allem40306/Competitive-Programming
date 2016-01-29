#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int m[101][101], i, j, k, n, r, u, v, s, d, t, tc, ntc;
	cin >> ntc;
	for (tc = 1; tc <= ntc; tc++){
		cin >> n >> r;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++)
				m[i][j] = 101;
			m[i][i] = 0;
		}
		for (i = 0; i < r; i++){
			cin >> u >> v;
			m[u][v] = m[v][u] = 1;
		}
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
		cin >> s >> d;
		t = 0;
		for (k = 0; k < n; k++)
			t = max(t, m[s][k] + m[k][d]);
		cout << "Case " << tc << ": " << t << endl;
	}
}
