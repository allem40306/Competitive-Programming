#include <cstdio>

int main(){
	long long int n,m;
	bool b=0;
	while(scanf("%lld",&n)!=EOF){
		if(n<0){b=1;n*=-1;} 
		else b=0;
		m=1;
		for(int i=2;i*i<=n;i++){
			while(n%(i*i)==0){
				m*=i;
				n/=i*i;
			}
		}
		if(!n)printf("0");
		if(m>1)printf("%d",m);
		if(n>1)printf("_/%d",n);
		if(b)printf("i");
		printf("\n");
	}
}
