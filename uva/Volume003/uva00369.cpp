#include <iostream>
using namespace std;
#define N 105
#define MIN(x,y) x<y?x:y

int main(){
	int m, n;
	while (cin >> n >> m, n){
		int i, j, k;
		int a = MIN(n - m, m), b = n - a;
		long long int ans = 1;
		for (i = n, j = 1; i > b;i--){
			ans *= i;
			if (j <= a){ ans /= j; j++; }
		}
		for (; j < a; j++)
			ans /= j;
		printf("%d things taken %d at a time is %lld exactly.\n", n, m, ans);
	}
}