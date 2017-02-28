#include <cstdio>
#include <cmath>

int main(){
	int n,i;
	scanf("%d",&n);
	for(i=std::floor(std::sqrt(n));i>=0;i--)
		if(n%i==0)break;
	printf("%d %d\n",i,n/i);
}
