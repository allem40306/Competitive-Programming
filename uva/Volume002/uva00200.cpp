#include <bits/stdc++.h>
using namespace std;
const int N=30;
vector<int>v[N];
bool vis[N];
int deg[N];

void init(){
    for(int i=0;i<N;i++){
        v[i].clear();
    }
    memset(deg,0,sizeof(deg));
    memset(vis,0,sizeof(vis));
}

void dfs(){
    int ans;
    bool ok;
    while(1){
        ok=0;
        for(int i=0;i<30;i++){
            if(vis[i]&&deg[i]==0){
                ok=1;
                cout<<char('A'+i);
                deg[i]--;
                for(auto it:v[i]){
                    deg[it]--;
                }
            }
        }
        if(!ok)break;
    }

    return;
}

int main(){
    string s,t;
    while(cin>>s){
        init();
        while(cin>>t,t!="#"){
            for(int i=0;i<min(s.size(),t.size());i++){
                if(s[i]==t[i])continue;
                v[s[i]-'A'].push_back(t[i]-'A');
                deg[t[i]-'A']++;
                vis[s[i]-'A']=vis[t[i]-'A']=1;
                cout<<"~"<<s[i]<<t[i]<<'\n';
                break;
            }
            s=t;
        }
        dfs();
        cout<<'\n';
    }
}
