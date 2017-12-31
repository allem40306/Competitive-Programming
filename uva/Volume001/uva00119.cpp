#include <bits/stdc++.h>
using namespace std;
const int N=15;
int main(){
    int n,m,p,a[N];
    string s,b[N];
    bool bb=0;
    map<string,int>ma;
    while(cin>>n){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            cin>>s;
            b[i]=s;
            ma[s]=i;
        }
        for(int i=0;i<n;i++){
            cin>>s>>p>>m;
            if(!m)continue;
            p/=m;
            a[ma[s]]-=m*p;
            while(m--){
                cin>>s;
                a[ma[s]]+=p;
            }
        }
        if(bb)cout<<'\n';
        bb=1;
        for(int i=0;i<n;i++){
            cout<<b[i]<<' '<<a[i]<<'\n';
        }
    }
}
