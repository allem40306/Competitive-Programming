#include <cstdio>
#define N 50005
int spof[N] = { 0, 1 }, lspof[N] = { 0, 1 }, num[N] = {0,1};
//#define scanf scanf_s
void bulit(){
	for (int i = 3, j; i<=1000; i += 2){
		if (!num[i]){
			for (j = 3; i*j<=N; j += 2)
				num[i*j] = i;
		}
	}
	for (int i = 2; i<N; i++){
		if (num[i] || i % 2 == 0)
			spof[i] = (i % 2 == 0) ? spof[i / 2] + 2 : spof[i / num[i]] + num[i];
		else 
			spof[i]=i;
		lspof[i] = (spof[i] == i ? 1 : 1 + lspof[spof[i]]);
	}
}

int main(){
	bulit();
	int t, a, b, ti = 1, i, ans;
	for (scanf("%d", &t); ti <= t; printf("Case #%d:\n%d\n", ti++, ans)){
		scanf("%d %d", &a, &b); ans = 2;
		if (a>b)a += b, b = a - b, a -= b;
		for (i = a; i <= b; i++)
			ans = (ans>lspof[i]) ? ans : lspof[i];
	}
}
