#include <cstdio>
#define Min(x,y)(x<y?x:y)
bool f(long long n,long long m){
	for(long long i=1;i<m/2;i++)
	if(i*(m-1)==n)return 1;
}
long long che(long long n,long long m,long long ans){
	if(n<m)m+=n,n=m-n,m-=n;
	printf("%lld %lld\n",n,m);
	if(n%m==0&&(printf("%lld\n",n/m)))return n/m;	
	else if(f(n,m))ans=Min(m,che(n-m,m,0));
	else ans+=1+che(n-m,m,0),printf("%lld\n",ans);
	return ans;
}
int main() {
	long long t,n,m,c=0,d;
	scanf("%lld %lld",&n,&m);
	printf("%lld\n",che(n,m,0));
}
