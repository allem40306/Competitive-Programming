#include <bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,q,x,y,djs[N];

void init(){
    for(int i=0;i<N;i++){
        djs[i]=i;
    }
}

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

void U(int x,int y){
    int xx=F(x),yy=F(y);
    djs[xx]=yy;
}

int main(){
    init();
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        U(x,y);
    }
    for(int i=0;i<q;i++){
        cin>>x>>y;
        if(F(x)==F(y)){
            cout<<":)\n";
        }else{
            cout<<":(\n";
        }
    }
}
