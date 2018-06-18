#include <iostream>
#include <cmath>
int main(){
	long long ans=0,n,x;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		ans+=i*x;
	}
	printf("%lld",ans);
}
