#include <bits/stdc++.h>
using namespace std;
int k,x,y,ans;

void dfs(int k,int a,int b){
    if(!k)return;
    if(a+k>=x&&a-k<=x&&b+k>=y&&b-k<=y)ans++;
    dfs(k>>1,a+k,b+k);
    dfs(k>>1,a+k,b-k);
    dfs(k>>1,a-k,b+k);
    dfs(k>>1,a-k,b-k);
}

int main(){
    while(cin>>k>>x>>y,k||x||y){
        ans=0;
        dfs(k,1024,1024);
        cout<<ans<<'\n';
    }
}
