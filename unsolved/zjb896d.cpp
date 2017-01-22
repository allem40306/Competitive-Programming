#include <iostream>
#include <cstring>
#define N 7500000
#define M 100005
int arr[M], a[N], b[N];
void bulit(int* b, int n){
	memset(arr, 0, sizeof(arr));
	int x, i = 0;
	for (; i<n; i++){
		scanf("%d", &x);
		arr[x]++;
	}
	for (i = x = 0; i<M; i++)
		while (arr[i]--)
			b[x++] = i;
}
int n, m;
void solve(long long ans, int* a, int *b){
	int ai = 0, bi = 0;
	for (; ai<n&&bi<m; ai++){
		if (a[ai] >= b[bi]){
			ans += a[ai];
			bi++;
		}
	}
	if (bi != m)printf("NO %d\n", m - bi);
	else printf("YES %d\n", ans);
}
int main(){
	scanf("%d %d", &n, &m);
	bulit(&a[0], n);
	bulit(&b[0], m);
	solve(0, &a[0], &b[0]);
}

