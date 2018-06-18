#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000005

int main(){
	static int n, a[N], i, x, ans = 0;
	bool b = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)scanf("%d", &a[i]);
	sort(a, a + n);
	for (i = n - 2, x = a[n - 1]; i >= 0; i--){
		if (a[i] != x){
			if (b){ x = a[i]; b = !b; }
			else { ans += x - a[i]; x = a[i]; b = !b; }
		}
	}
	printf("%d\n", ans + (!b)*x);
}
