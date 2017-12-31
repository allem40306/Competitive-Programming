#include <bits/stdc++.h>
using namespace std;
const int N=50005;

int main(){
    int n,m,x,sum,ans;
    bool dp[N];
    cin>>n;
    while(n--){
        memset(dp,0,sizeof(dp));
        sum=0;
        cin>>m;
        while(m--){
            cin>>x;
            sum+=x;
            for(int j=sum;j-x>=0;j--){
                if(!(j-x)||dp[j-x]){
                    dp[j]=1;
                }
            }
        }
        ans=sum;
        for(int i=1;i<=sum/2;i++){
            if(dp[i]){
                ans=sum-2*i;
            }
        }
        cout<<ans<<'\n';
    }
}
