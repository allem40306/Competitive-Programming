#include <iostream>
#include <cstdio>
using namespace std;
#define N 1000001
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
	while (cin >> n,n){
		int nn = n;
		int count = 0;
		for (int i = 0; n&&p[i] <= n; i++){
			if (!(n%p[i]))count++;
			while (!(n%p[i])){
				n /= p[i];
			}
		}
		printf("%d : %d\n", nn, count);
	}
}