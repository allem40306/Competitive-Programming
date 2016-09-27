#include <iostream>  
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 100000
static int t, n, k, ti = 0, a[N], ans;

void bin(int L, int R){
	if (L >= R)return;
	int M = (L + R) >> 1, kk = k, r = -1;
	for (int i = 0; i < n&&kk >= 0; i++){
		if (a[i]>r){ r = a[i] + 2 * M; kk--; }
	}
	if (kk >= 0) { if (ans > M)ans = M; bin(L, M); }
	else bin(M + 1, R);
	return;
}

int main(){
	for (cin >> t; ti < t; ti++){
		cin >> n >> k;
		for (int ni = 0; ni < n; ni++)
			cin >> a[ni];
		sort(a, a + n);
		ans = N*N;
		bin(0, a[n - 1] - a[0]);
		printf("%d\n", ans);
	}
}