#include <cstdio>
int a[20];

void ooo2(int f, int n, int m,int x){
	if (n == m){
		printf("{");
		for (int i = 0; i<n; i++){
			if (i)printf(",%d", a[i]);
			else printf("%d", a[i]);
		}
		printf("}\n");
	}
	else{
		for (int i = f + 1; i <= x; i++){
			a[n] = i;
			ooo2(i, n + 1, m,x);
		}
	}
}

void ooo(int n){
	for (int i = 1; i <= n; i++){
		ooo2(0, 0, i,n);
	}
}

int main(){
	int t, ti = 0, n;
	for (scanf("%d", &t); ti<t; ti++){
		scanf("%d", &n);
		if (ti)printf("\n");
		printf("{0}\n");
		ooo(n);
	}
}
