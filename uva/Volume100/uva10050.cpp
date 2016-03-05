#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 100
#define M 3651
#define rest(x) (x%7!=0&&x%7!=6)
int main(){
	int t, n, p;
	cin >> t;
	while (t--){
		cin >> n >> p;
		int h[N], d[M];
		for (int i = 0; i < p; i++)cin >> h[i];
		memset(d, 0, sizeof(d));
		for (int j = 0; j < p; j++)
			for (int j2 = 1; h[j]*j2 <= n; j2++)
			d[h[j]*j2] = 1;
		int ans = 0;
		for (int k = 1; k <= n; k++)
			ans += (rest(k) && d[k]);
		printf("%d\n", ans);
	}
}