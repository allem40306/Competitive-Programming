#include <iostream>
#include <vector>
using namespace std;
const int N=25;
const long long int INF=1000000000000000000;
long long t,n,m,s,e,f,adj[N][N];
long long a,b,c,d,cc;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            adj[i][j]=INF;
        }
    }
}
int main(){
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>m>>s>>e>>f;
        init();
        for(int i=0;i<m;i++){
            cin>>a>>b>>c>>d>>cc;
            adj[a][b]=adj[b][a]=(f>d)*cc*f+(f<=d)*c*f;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=0;j<i;j++){
                    adj[i][j]=adj[j][i]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        cout<<adj[s][e]<<'\n';
    }
}
