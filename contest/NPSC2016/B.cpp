#include <cstdio>
#define N 1000005
int main(){
    static long long  n,ni=1,a[N]={},ans=0; bool b;
    for(scanf("%lld",&n);ni<=n;ni++)scanf("%lld",&a[ni]),a[ni]+=a[ni-1];
    long long i,j,v=0;
    for(i=1;i<=n;i++){
        for(b=0,j=v;j<i;j++){
        //printf("%lld %lld %lld %lld\n",i,j,a[i]-a[j],i-j);
        if(a[i]-a[j]<0LL)ans+=(n-i+1)*(i-j),j=v=i,b=1;       
        }
        if(!b)v=i-1;
    }
    printf("%lld\n",ans);
}
