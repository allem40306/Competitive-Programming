#include <iostream>
using namespace std;
#define N 100005
#define Max(x,y) x>y?x:y

int main(){
	int t, n, a[N], ti = 0;
	for (cin >> t; ti<t; ti++){
		cin >> n;
		for (int i = 0; i<n; i++)cin >> a[i];
		int ans = Max(a[n - 1], n - 1);
		for (int j = n - 2; j >= 0; j--)
			ans = max(ans + 1, a[j]);
		printf("%d\n", ans);
	}
}