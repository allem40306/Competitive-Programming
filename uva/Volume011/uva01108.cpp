#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=50005;
vector<int>v[N],bcc[N];
LL dep[N],bccno[N],low[N],time_cnt,bcc_cnt;
bitset<N>is_AP;

struct Edge{
    int s,t;
};
stack<Edge>st;
void init(){
    for(int i=0;i<N;i++){
        v[i].clear();
    }
    while(!st.empty())st.pop();
    memset(dep,-1,sizeof(dep));
    memset(low,-1,sizeof(low));
    memset(bccno,0,sizeof(bccno));
    is_AP.reset();
    time_cnt=bcc_cnt=0;
}

int dfs(int s,int fa){
    int child=0;
    dep[s]=low[s]=time_cnt++;
    for(auto t:v[s]){
        Edge e=(Edge){s,t};
        if(dep[t]==-1){
            st.push(e);
            child++;
            dfs(t,s);
            low[s]=min(low[s],low[t]);
            if(dep[s]<=low[t]){
                is_AP[s]=1;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                while(1){
                    Edge x=st.top(); st.pop();
                    if(bccno[x.s]!=bcc_cnt){
                        bcc[bcc_cnt].push_back(x.s);
                        bccno[x.s]=bcc_cnt;
                    }
                    if(bccno[x.t]!=bcc_cnt){
                        bcc[bcc_cnt].push_back(x.t);
                        bccno[x.t]=bcc_cnt;
                    }
                    if(x.s==s&&x.t==t)break;
                }
            }
        }else{
            if(dep[s]>dep[t]&&t!=fa){
                st.push(e);
                low[s]=min(low[s],dep[t]);
            }
        }
    }
    if(fa<0&&child==1){
        is_AP[s]=0;
    }
    return low[s];
}

int main(){
    int n,ti=1,a,b;
    while(cin>>n,n){
        init();
        for(int i=0;i<n;i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(low[i]<0)dfs(i,-1);
        }
        LL ans1=0,ans2=1;
        for(int i=1;i<=bcc_cnt;i++){
            int cut_cnt=0;
            for(auto j:bcc[i]){
                if(is_AP[j])cut_cnt++;
            }
            if(cut_cnt==1){
                ans1++;
                ans2*=(long long)(bcc[i].size()-cut_cnt);
            }
        }
        if(bcc_cnt==1){
            ans1=2;
            ans2*=(bcc[1].size())*(bcc[1].size()-1)/2;
        }
        cout<<"Case "<<ti++<<": "<<ans1<<' '<<ans2<<'\n';
    }
}
