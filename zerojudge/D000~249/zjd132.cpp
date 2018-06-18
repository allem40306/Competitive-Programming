#include <stdio.h>
#define maxn 1010
//#define scanf scanf_s

int main(){
	int n, a[maxn], b[maxn];
	int kase = 0;
	while (scanf("%d", &n) == 1 && n){
		printf("Game %d:\n", ++kase);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (;;){
			int aa = 0, bb = 0,bsum=0;
			for (int i = 0; i < n; i++){
				scanf("%d", &b[i]);
			bsum+=b[i];
				if (a[i] == b[i])aa++;
			}
			if (bsum == 0)break;
			for (int d = 1; d <= 9; d++){
				int c1 = 0, c2 = 0;
				for (int i = 0; i < n; i++){
					if (a[i] == d)c1++;
					if (b[i] == d)c2++;
				}
				if (c1 < c2)bb += c1;
				else bb += c2;
			}
			printf("    (%d,%d)\n", aa, bb - aa);
		}
	}
}
