#include <bits/stdc++.h>
using namespace std;
const int N=1005;
const int INF=100000005;
struct edge{
    int t,w;
    edge(){};
    edge(int t,int w):t(t),w(w){};
};
struct node{
    int s,r,c;//rest,cost
    node(){};
    node(int s,int r,int c):s(s),r(r),c(c){};
    bool operator <(const node& b)const{
        return c<b.c;
    }
};
int dp[N][N];
queue<node>hp;
void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j]=INF;
        }
    }
    while(!hp.empty())hp.pop();
}
int main(){
    freopen("ooo.txt","r",stdin);
    freopen("test.txt","w",stdout);
    int n,m,p[N],x,y,w;
    vector<edge>v[N];
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        v[x].push_back(edge(y,w));
        v[y].push_back(edge(x,w));
    }
    int q,c,s,e,ans;
    node k;
    cin>>q;
    while(q--){
        cin>>c>>s>>e;
        init();
        hp.push(node(s,0,0));
        dp[s][0]=0;
        while(!hp.empty()){
            k=hp.front(); hp.pop();
            if(k.s==e)break;
//            printf("base %d %d %d\n",k.s,k.r,k.c);
            for(auto x:v[k.s]){
                for(int i=max(x.w-k.r,0);i+k.r<=c;i++){//add i(L)
                    if(k.c+i*p[k.s]<=dp[x.t][i+k.r-x.w]){
                        dp[x.t][i+k.r-x.w]=k.c+i*p[k.s];
                        hp.push(node(x.t,i+k.r-x.w,dp[x.t][i+k.r-x.w]));
//                        printf("push %d %d %d\n",x.t,i+k.r-x.w,dp[x.t][i+k.r-x.w]);
                    }
                }
            }
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<=c;j++){
//                cout<<dp[i][j]<<' ';
//            }cout<<'\n';
//        }
        ans=*(min_element(dp[e],dp[e]+c+1));
        if(ans==INF){
            cout<<"impossible\n";
        }else{
            cout<<ans<<'\n';
        }
    }
}
