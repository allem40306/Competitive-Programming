#include <iostream>
#include <cstdio>
using namespace std;
#define N 2000000
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
	while (cin >> n){
		int n1 = 0, nn = n;
		while (n){
			n1 = n1 * 10 + n % 10;
			n /= 10;
		}
		if (ox[nn])printf("%d is not prime.\n", nn);
		else if (ox[n1]||nn==n1)printf("%d is prime.\n", nn);
		else printf("%d is emirp.\n", nn);
	}
}