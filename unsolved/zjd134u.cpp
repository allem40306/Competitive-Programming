#include <iostream>
using namespace std;
#define N 105
#define MIN(x,y) x<y?x:y

int main(){
	unsigned long long int m, n, i, j, k, a,ans;
	while (cin >> n >> m, n || m){
		a = MIN(n - m, m);
		ans = 1;
		for (i = n, j = 1; j <= a; i--, j++){
			ans *= i;
			ans /= j;
		}
		printf("%llu things taken %llu at a time is %llu exactly.\n", n, m, ans);
	}
}
