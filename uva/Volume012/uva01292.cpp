#include <bits/stdc++.h>
using namespace std;
const int N = 1505;
vector<int>G[N];
bitset<N> vis;
int dp[N][N];

void add_Edge(int x, int y){
    G[x].push_back(y);
    G[y].push_back(x);
}

void init(int n){
    for(int i = 0; i <= n; i++)G[i].clear();
    for(int i = 0, x, y, t; i < n; i++){
        static char ch;
        cin >> x >> ch >> ch >> t >> ch;
        while(t--){
            cin >> y;
            add_Edge(x, y);
        }
    }
}

void dfs(int s){
    vis[s] = 1;
    dp[s][0] = 0;
    dp[s][1] = 1;
    for(int it: G[s]){
        if(vis[it])continue;
        dfs(it);
        dp[s][0] += dp[it][1];
        dp[s][1] += min(dp[it][0], dp[it][1]);
    }
}

void sol(int n){
    static int ans;
    ans = 0;
    vis.reset();
    for(int i = 0; i < n;i++){
        if(vis[i])continue;
        dfs(i);
        ans += min(dp[i][0], dp[i][1]);
    }
    cout << ans << '\n';
}

int main(){
    int n;
    while(cin >> n){
        init(n);
        sol(n);
    }
}