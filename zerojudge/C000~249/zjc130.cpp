#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n,t,ans[N],x;
bool o;
vector<int>v;

void dfs(int r,int d,int sum){
    if(sum>n)return;
    if(sum==n){
        for(int i=0;i<d;i++){
            if(i)cout<<'+';
            cout<<ans[i];
        }
        cout<<'\n';
        o=1;
        return;
    }

    int m=0;
    for(int i=r;i<t;i++){
        if(v[i]==m)continue;
        m=ans[d]=v[i];
        dfs(i+1,d+1,sum+v[i]);
    }
}

int main(){
    while(cin>>n>>t){
        if(!n)break;
        v.clear();
        for(int i=0;i<t;i++){
            cin>>x;
            v.push_back(x);
        }
        o=0;
        cout<<"Sums of "<<n<<":\n";
        dfs(0,0,0);
        if(!o)cout<<"NONE\n";
    }
}
