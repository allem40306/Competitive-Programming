#include <bits/stdc++.h>
using namespace std;
const int N=500005;
vector<int>v;
bitset<N>b;
int spof[N]={0,1,2};
void prime(){
    v.clear();
    b.reset();
    for(int i=2;i<N;i++){
        if(!b[i]){
            spof[i]=i;
            v.push_back(i);
            for(int j=2;j*i<N;j++){
                b[i*j]=1;
                spof[i*j]=spof[i]+spof[j];
            }
        }
    }
}
int lspof(int x){return spof[x]==x?1:1+lspof(spof[x]);}
int main(){
    prime();
    int t,n,m,ans;
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>n>>m;
        if(n>m)swap(n,m);
        ans=0;
        for(int i=n;i<=m;i++){
            ans=max(ans,lspof(i));
        }
        cout<<"Case #"<<ti<<":\n";
        cout<<ans<<'\n';
    }
}
