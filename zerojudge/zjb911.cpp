#include <cstdio>

int main(){
	unsigned long long int n;
	int ans;
	while(scanf("%d",&n)!=EOF){
		ans=1;
		while(n/=2)ans++;
		printf("%d\n",ans);
	}
}
