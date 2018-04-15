#include <iostream>
using namespace std;
#define N 1000000

int main() {
	int t, ti = 0, m, n;
	static int a[N];
	for (cin >> t; ti < t; ti++){
		cin >> n >> m;
		for (int ni = 0; ni < n; ni++){
			cin >> a[ni];
			a[ni] = (a[ni] % m ? a[ni] % m : m);
		}
		static bool b[N] = { 1 };
		for (int i = 0; i < n; i++)
			for (int j = m; j >= 0; j--)
				if (b[j])b[((j + a[i]) % m ? (j + a[i]) % m : m)] = 1;
		printf(b[m] ? "YES\n" : "NO\n");
	}
}