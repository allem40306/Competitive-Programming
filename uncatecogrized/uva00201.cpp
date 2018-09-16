#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,x,y,sh[N][N],sv[N][N];
#define debug
void init(){
    memset(sh,0,sizeof(sh));
    memset(sv,0,sizeof(sv));
}

int dfs(int len){
    int ans=0;
    for(int i=1;i+len-1<=n;i++){
        for(int j=1;j+len-1<=n;j++){
            if((sh[i][j+len-1]-sh[i][j-1]==len)&&(sv[i+len-1][j]-sv[i-1][j]==len)){
                    #ifdef debug
                        cout<<i<<' '<<j<<' '<<i+len-1<<' '<<j+len-1<<'\n';
                    #endif
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int ti=1;
    char ch;
    while(cin>>n>>m){
        for(int i=0;i<m;i++){
            cin>>ch>>x>>y;
            if(ch=='H'){
                sh[x][y]++;
            }else{
                sv[x][y]++;
            }
        }
        #ifdef debug
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    cout<<sh[i][j]<<' ';
                }cout<<'\n';
            }
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    cout<<sv[i][j]<<' ';
                }cout<<'\n';
            }
        #endif // debug
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                sh[i][j]+=sh[i][j-1];
                sv[i][j]+=sv[i-1][j];
            }
        }
        #ifdef debug
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    cout<<sh[i][j]<<' ';
                }cout<<'\n';
            }
            for(int i=0;i<=n;i++){
                for(int j=0;j<=n;j++){
                    cout<<sv[i][j]<<' ';
                }cout<<'\n';
            }
        #endif // debug
        if(ti>1)cout<<"\n**********************************\n";
        cout<<"Problem #"<<ti++<<"\n\n";
        int v;
        bool ans=0;
        for(int i=1;i<=n;i++){
            v=dfs(i);
            if(!v)continue;
            cout<<v<<" square (s) of size "<<i<<'\n';
        }
        if(!ans){
            cout<<"No completed squares can be found.\n";
        }
    }
}
