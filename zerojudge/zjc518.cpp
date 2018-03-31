#include <bits/stdc++.h>
using namespace std;
const int N=200;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,ss,tt,a[N]={};
    string p,s,t;
    list<int>li[N];
    list<int>::iterator it;
    cin>>n>>m>>p>>s>>t;
    for(int i=0;i<N;i++){
        li[i].push_back(i);
    }
    for(int i=0;i<m;i++){
        ss=int(s[i]);
        tt=int(t[i]);
        if(li[ss].size()==0)continue;
        li[tt].merge(li[ss]);
    }
    for(int i=0;i<N;i++){
        for(it=li[i].begin();it!=li[i].end();it++){
            a[*it]=i;
        }
    }
    for(int i=0;i<n;i++){
        p[i]=char(a[int(p[i])]);
    }
    cout<<p<<'\n';
}
