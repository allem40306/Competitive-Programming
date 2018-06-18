#include <cstdio>

int cou(int a,int b,int t){
	int ans=0;
	ans+=b/t;
	ans-=a/t+(a%t>0);
	return ans+1;
}

int main(){
	int a,b,t,c,d,e;
	scanf("%d %d",&a,&b);
	if(a>b)t=a,a=b,b=t;
	c=cou(a,b,2);
	d=cou(a,b,3);
	e=c+d-cou(a,b,6);
	printf("%d %d %d\n",c,d,e);
}
