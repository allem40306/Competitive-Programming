#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int p[N],r[N];
void init(){
    for(int i=0;i<N;i++){
        p[i]=i;
    }
    return;
}
int f(int x){x==p[x]?x:f(p[x]);}
int main(){
    int n,m,a,b,aa,bb;
    init();
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        aa=f(a);
        bb=f(b);
        if(aa==bb){
            cout<<r[aa]<<'\n';
            continue;
        }
        p[aa]=bb;
        r[bb]=i;
        cout<<"Mukyu\n";
    }
}
