#include <iostream>
#include <algorithm>
#define N 1000000
//#define scanf scanf_s 
struct goo{ int i, j; };
static goo a[N];
bool cmp(goo a, goo b){ return a.i<b.i; }
int main(){
	int n, i, ans, t, ti = 0;
	for (scanf("%d", &t); ti<t; ti++){
		scanf("%d", &n); ans = 0;
		for (i = 0; i<n; i++)a[i].j = i;
		for (i = 0; i<n; i++)scanf("%d", &a[i].i);
		std::sort(a, a + n, cmp);
		for (i = 0; i<n; i++)
			ans += (i % 2) != (a[i].j % 2);
		printf("%d\n", ans/2);
	}
}
