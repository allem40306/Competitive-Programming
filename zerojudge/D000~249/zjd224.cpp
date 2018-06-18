#include <cstdio>

int main(){
	unsigned long long n;
	while(scanf("%llu",&n)!=EOF&&(n=n/2+1))
		printf("%llu\n",(1+n)*n/2); 
}
