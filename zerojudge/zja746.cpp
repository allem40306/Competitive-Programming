#include <bits/stdc++.h>
using namespace std;
const int N=505;
int main(){
    int n,m,x,y,z,w,s,t;
    bool a[N][N];
    while(cin>>n>>m){
        memset(a,0,sizeof(a));
        cin>>x>>y;
        for(int i=1;i<m;i++){
            cin>>z>>w;
            if(x==z){
                s=min(y,w);
                t=max(y,w);
                for(int j=s;j<=t;j++){
                    a[x][j]=1;
                }
            }else{
                s=min(x,z);
                t=max(x,z);
                for(int j=s;j<=t;j++){
                    a[j][y]=1;
                }
            }
            x=z;
            y=w;
        }
        for(int i=0;i<n+2;i++){
            cout<<'-';
        }
        cout<<'\n';
        for(int i=1;i<=n;i++){
            cout<<'|';
            for(int j=1;j<=n;j++){
                if(a[i][j])cout<<'*';
                else cout<<' ';
            }
            cout<<"|\n";
        }
        for(int i=0;i<n+2;i++){
            cout<<'-';
        }
        cout<<'\n';
    }
}
