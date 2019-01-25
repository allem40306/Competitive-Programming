#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int BIT[N];
void add(int i,int v){
    for(;i<N;i+=(i&(-i))){
        BIT[i]+=v;
    }
}
int sum(int i){
    int ret=0;
    for(;i>0;i-=(i&(-i))){
        ret+=BIT[i];
    }
    return ret;
}

int main(){
    int t,n,m;
    int p[N];
    cin>>t;
    while(t--){
        for(int i=0;i<N;i++)BIT[i]=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            p[i]=n-i+1;
            add(p[i],1);
        }
        int tot=n;
        for(int i=0,x;i<m;i++){
            cin>>x;
            if(i)cout<<' ';
            cout<<(n-sum(p[x]));
            add(p[x],-1);
            p[x]=++tot;
            add(p[x],1);
        }cout<<'\n';
    }
}