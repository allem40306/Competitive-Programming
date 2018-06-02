#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=35;

LL ans(int L,int R,int ql,int qr,LL v){
    if(qr<L||R<ql)return 0;
    if(ql<=L&&R<=qr)return v;
    int M=(L+R)>>1;
    return ans(L,M,ql,qr,v/3*2)+ans(M+1,R,ql,qr,v/3);
}

int main(){
    LL x[N]={1},y[N]={1};
    for(int i=1;i<N;i++){
        x[i]=x[i-1]*2;
        y[i]=y[i-1]*3;
    }
    int a,b,k,t,ti=1;
    cin>>t;
    while(t--){
        cin>>k>>a>>b;
        cout<<"Case "<<ti++<<": "<<ans(1,x[k],1,b,y[k])-ans(1,x[k],1,a-1,y[k])<<'\n';
    }
}
