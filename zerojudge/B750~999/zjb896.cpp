#include <stdio.h>
#include <cstring>
#define N 7500000
#define M 100005
int arr[M], a[N], b[N],n, m;
long long ans=0;

int main(){
	scanf("%d %d", &n, &m);
	memset(arr, 0, sizeof(arr));
	int x, i = 0;
	for (; i<n; i++){
		scanf("%d", &x);
		arr[x]++;
	}
	for (i = x = 0; i<M; i++)
		while (arr[i]--)
			a[x++] = i;
	memset(arr, 0, sizeof(arr));
	for (i = 0; i<m; i++){
		scanf("%d", &x);
		arr[x]++;
	}
	for (i = x = 0; i<M; i++)
		while (arr[i]--)
			b[x++] = i;
	int ai = 0, bi = 0;
	for (; ai<n&&bi<m; ai++){
		if (a[ai] >= b[bi]){
			ans += a[ai];
			bi++;
		}
	}
	if (bi != m)printf("NO %d\n", m - bi);
	else printf("YES %lld\n", ans);
}

