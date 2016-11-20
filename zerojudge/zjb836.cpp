#include <cstdio>

int main(){
	long long int n,m;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		if(!m||!n)printf("Go Kevin!!\n");
		else{
			bool b=0;
			for(int i=0;(2+i*m)*(i+1)/2<=n;i++)
			if((2+i*m)*(i+1)/2==n)b=1;
			if(b)printf("Go Kevin!!\n");
			else printf("No Stop!!\n");
		}
	}
} 
