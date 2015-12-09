#include <iostream>
#include <cstdio>
using namespace std;
#define N 46341
int ox[N], p[N], pr;

void PrimeTable(){
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++){
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

int main(){
	PrimeTable();
	int n;
	while (cin >> n, n){
		int nn = n, flag = 0;
		printf("%d = ", n);
		if (n < 0){ printf("-1"); n *= -1; flag = 1; }
		for (int i = 0; p[i] && p[i] < n&&i < N; i++){
			while (n%p[i] == 0){
				if (flag)printf(" x ");
				printf("%d", p[i]);
				n /= p[i];
				flag = 1;
			}
		}
		if (n>1){
			if (flag)printf(" x ");
			printf("%d", n);
		}
		printf("\n");
	}
}