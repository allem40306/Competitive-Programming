#include <cstdio>

int main(){
	int x,y,z,n,ni=0,m;
	for(scanf("%d",&n);ni<n;ni++){
		scanf("%d",&m);
		x=m;
		while(m>=3){
			x+=m/3;
			m=m/3+m%3;
		}
		printf("%d %d\n",x,m);
	}
}
