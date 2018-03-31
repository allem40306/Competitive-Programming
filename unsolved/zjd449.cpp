#include <bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=1000005;
int d[M],f[M],p[N],id;
int fi(int x){return x==f[x]?x:f[x]=fi(f[x]);}
void init(int n){
    for(int i=1;i<=n;i++){
        d[i]=1;
        f[i]=p[i]=i;
    }
}
void uni(int y,int z){
    if(d[y]<d[z]){
        f[z]=y;
        d[y]+=d[z];
    }else{
        f[y]=z;
        d[z]+=d[y];
    }
}
int main(){
    int n,m,x,y,z,yy,zz,ans;
    while(cin>>n>>m){
        init(n);
        ans=n;
        id=n+1;
        while(m--){
            cin>>x;
            if(x==1){
                cin>>y>>z;
                yy=fi(y);
                zz=fi(z);
                if(yy==zz)continue;
                uni(yy,zz);
                ans--;
            }else{
                cin>>y;
                yy=fi(y);
                if(d[yy]>1){
                    f[id]=id;
                    d[id]=1;
                    p[y]=id++;
                    d[yy]--;
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
