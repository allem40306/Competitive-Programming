#include <cstdio>
#define N 50000
//#define scanf scanf_s
int m, n, ni, x, a[N], a1, a2;
int bf(int n, int L, int R) {
	int M = (L + R) >> 1;
	if (n < a[L])return L-1;
	if (L == R)return L;
	if (n > a[M])return bf(n, M + 1, R);return bf(n, L, M);
}
int bf2(int n, int L, int R) {
	int M = (L + R) >> 1;
	if (n > a[R])return R + 1;
	if (L == R)return R;
	if (n < a[M])return  bf2(n, L, M);return bf2(n, M + 1, R);
}
int main(){
	scanf("%d", &n);
	for (ni = 0; ni<n; ni++)scanf("%d", &a[ni]);
	scanf("%d", &m);
	while (m--){
		scanf("%d", &x);
		a1 = bf(x, 0, n - 1), a2 = bf2(x, 0, n - 1);
		while (a1>=0&&a[a1] == x)a1--;
		while (a2<n&&a[a2] == x)a2++;
		a1 >= 0 ? printf("%d ", a[a1]) : printf("X ");
		a2 < n ? printf("%d\n", a[a2]) : printf("X\n");
	}
}
