#include <bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>v[N];
long long ans;
bitset<N>h;

long long dfs(int p){
    if(!v[p].size())return 0;
    long long mxd=0;
    for(auto it:v[p]){
        mxd=max(mxd,dfs(it)+1);
    }
    ans+=mxd;
    return mxd;

}

int main(){
    int n,m,x;
    h.set();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        while(m--){
            cin>>x;
            v[i].push_back(x);
            h[x]=0;
        }
    }
    ans=0;
    for(int i=1;i<=n;i++){
        if(!h[i])continue;
        cout<<i<<'\n';
        dfs(i);
    }
    cout<<ans<<'\n';
}
