#include <bits/stdc++.h>
using namespace std;
int n,a[20];
string s="+- ";
void dfs(int v,int sum,int res){
//    cout<<1;
//    for(int i=2;i<v;i++){
//        cout<<s[a[i]]<<i;
//    }
//    cout<<"->"<<sum<<' '<<res<<'\n';
    if(v==n+1){
        if(sum==0){
            cout<<1;
            for(int i=2;i<=n;i++){
                cout<<s[a[i]]<<i;
            }
            cout<<'\n';
        }
        return;
    }
    a[v]=2;
    if(v<10){
        if(res>0)dfs(v+1,sum-res+(res*10+v),res*10+v);
        else dfs(v+1,sum-res+(res*10-v),res*10-v);
    }else{
        if(res>0)dfs(v+1,sum-res+(res*100+v),res*100+v);
        else dfs(v+1,sum-res+(res*100-v),res*100-v);
    }
    a[v]=0;
    dfs(v+1,sum+v,v);
    a[v]=1;
    dfs(v+1,sum-v,-v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n){
        dfs(2,1,1);
    }
}
