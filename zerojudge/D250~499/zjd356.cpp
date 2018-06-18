#include <cstdio>

int main(){
	double k,i=0,n;
	scanf("%lf",&k);
	for(n=1;;n++){
		i+=1/n;
		if(i>k)break;
	}
		
	printf("%.0lf",n);
}
