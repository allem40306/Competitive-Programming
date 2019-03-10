#include <bits/stdc++.h>
using namespace std;
const int N=105;
map<string,int>tb;
int st[3][3]={0,-1,1,1,0,-1,-1,1,0};
void init(){
    tb["scissors"]=0;
    tb["rock"]=1;
    tb["paper"]=2;
    return;
}

int main(){
    init();
    int n,k,p1,p2,r;
    string m1,m2;
    double w[N],t[N];
    bool f=0;
    while(cin>>n,n){
        cin>>k;
        if(f)cout<<'\n'; f=1;
        memset(w,0,sizeof(w));
        memset(t,0,sizeof(t));
        int m=k*n*(n-1)/2;
        for(int i=0;i<m;i++){
            cin>>p1>>m1>>p2>>m2;
            r=st[tb[m1]][tb[m2]];
            if(!r)continue;
            t[p1]+=1; t[p2]+=1;
            if(r>0)w[p1]+=1;
            else w[p2]+=1;
        }
        for(int i=1;i<=n;i++){
            if(t[i]!=0.0)cout<<fixed<<setprecision(3)<<w[i]/t[i]<<'\n';
            else cout<<"-\n";
        }
    }
}
