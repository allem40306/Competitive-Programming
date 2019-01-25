#include <bits/stdc++.h>
using namespace std;
const int N=2005;
const int INF=(1<<30);
#define Lc(x) (x<<1)
#define Rc(x) ((x<<1)+1)

struct Seg{
    int n;
    int Max[N][N],Min[N][N];
    int x1,y1,x2,y2;
    int x,y,v;
    int xo,xleaf;
    int vmin,vmax;
    void query(int o,int L,int R){
        // cout<<L<<'-'<<R<<'\n';
        if(y1<=L&&R<=y2){
            vmax=max(vmax,Max[xo][o]);
            vmin=min(vmin,Min[xo][o]);
            return;
        }
        int M=(L+R)>>1;
        if(y1<=M)query(Lc(o),L,M);
        if(M<y2)query(Rc(o),M+1,R);
    }
    void query2D(int o,int L,int R){
        // cout<<L<<' '<<R<<'\n';
        if(x1<=L&&R<=x2){
            xo=o;
            query(1,1,n);
            return;
        }
        int M=(L+R)>>1;
        if(x1<=M)query2D(Lc(o),L,M);
        if(M<x2)query2D(Rc(o),M+1,R);
    }
    void modify(int o,int L,int R){
        // cout<<L<<'-'<<R<<'\n';
        if(L==R){
            if(xleaf){
                Max[xo][o]=Min[xo][o]=v;
            }else{
                Max[xo][o]=max(Max[Lc(xo)][o],Max[Rc(xo)][o]);
                Min[xo][o]=min(Min[Lc(xo)][o],Min[Rc(xo)][o]);
            }
            return;
        }
        int M=(L+R)>>1;
        if(y<=M)modify(Lc(o),L,M);
        else modify(Rc(o),M+1,R);
        Max[xo][o]=max(Max[xo][Lc(o)],Max[xo][Rc(o)]);
        Min[xo][o]=min(Min[xo][Lc(o)],Min[xo][Rc(o)]);
    }
    void modify2D(int o,int L,int R){
        // cout<<L<<' '<<R<<'\n';
        if(L==R){
            xo=o; xleaf=1; modify(1,1,n);
            return;
        }
        int M=(L+R)>>1;
        if(x<=M)modify2D(Lc(o),L,M);
        else modify2D(Rc(o),M+1,R);
        xo=o; xleaf=0; modify(1,1,n);
    }
}T;

int main(){
    int n,q;
    char ch;
    cin>>n;
    T.n=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>T.v;
            T.x=i; T.y=j;
            T.modify2D(1,1,n);
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>ch;
        if(ch=='q'){
            cin>>T.x1>>T.y1>>T.x2>>T.y2;
            T.vmax=-INF;
            T.vmin=INF;
            T.query2D(1,1,n);
            cout<<T.vmax<<' '<<T.vmin<<'\n';
        }else{
            cin>>T.x>>T.y>>T.v;
            T.modify2D(1,1,n);
        }
    }
}