#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],ans[N];

void dfs(int d,int r){
    int now=-1;
    if(d==m){
        for(int i=0;i<m;i++){
            if(i)cout<<' ';
            cout<<ans[i];
        }
        cout<<'\n';
        return;
    }
    for(int i=r;i<n;i++){
        if(a[i]==now)continue;
        now=ans[d]=a[i];
        dfs(d+1,i+1);
    }
}

int main(){
    while(cin>>n>>m,n||m){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        dfs(0,0);
    }
}
