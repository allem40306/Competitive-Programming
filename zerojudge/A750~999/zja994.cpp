#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[20],ans,add,r;
unsigned int dp[1<<15],x,y;
int main(){
    while(cin>>n>>m){
        for(int i=1;i<=m;i++){
            cin>>a[i];
        }
        ans=n;
        dp[0]=1;
        for(int i=1;i<(1<<m);i++){
            x=dp[i-(i&(-i))]; y=a[__builtin_ffs(i&(-i))];
            if(x>n){dp[i]=n+1; continue;}
            add=y/__gcd(x,y)*(LL)x;
            if(add<=n){
                dp[i]=add;
                if(__builtin_popcount(i)%2){
                    ans-=n/add;
                }else{
                    ans+=n/add;
                }
            }else{
                dp[i]=n+1;
            }
        }
        cout<<ans<<'\n';
    }
}
