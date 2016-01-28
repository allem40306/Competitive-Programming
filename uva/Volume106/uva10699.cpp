#include <iostream>
#include <cstdio>
using namespace std;
#define N 1000001
int ox[N], p[N], pr;

int main(){
	int n;
	while (cin >> n,n){
		int nn = n;
		int count = 0;
		for (int i = 2; i <= n; i++){
			if (!(n%i)){
				count++;
			while (!(n%i))
				n /= i;
			}
		}
		printf("%d : %d\n", nn, count);
	}
}