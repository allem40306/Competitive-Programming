#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100005

int main(){
	long long n,t,a[N], ti = 0,ni,ans;
	for (scanf("%lld", &t); ti < t; ti++){
		scanf("%lld", &n); ans = 0;
		for (ni = 0; ni < n; ni++)scanf("%lld", &a[ni]);
		sort(a, a + n);
		for (ni = 1; ni <n; ni+=2)ans +=a[ni-(n%2==0)];
		printf("%lld\n",4*ans);
	}
}
