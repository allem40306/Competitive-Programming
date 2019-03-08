#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> G[N]; 
bitset<N> vis;
int dp[N][3];

void init(int n){
    for(int i = 1; i <= n; ++i)G[i].clear();
    for(int i = 1; i < n; ++i){
        static int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void dfs(int s){
    // cout << "de:" << s << '\n';
    vis[s] = true;
    dp[s][0] = 1;
    dp[s][1] = 0;
    dp[s][2] = N;
    for(int it: G[s]){
        if(vis[it])continue;
        dfs(it);
        dp[s][0] += min(dp[it][0], dp[it][1]);
        dp[s][1] += dp[it][2];
        if(dp[s][0] > N)dp[s][0] = N;
        if(dp[s][1] > N)dp[s][1] = N;
    }
    for(int it: G[s]){
        if(vis[it])continue;
        dp[s][2] = min(dp[s][2], dp[s][1] - dp[it][2] + dp[it][0]);
    }
    // cout << "de:" << s << ' ' << dp[s][0] << ' ' << dp[s][1] << ' ' << dp[s][2] << '\n';
    vis[s] = 0;
}

void sol(){
    vis.reset();
    dfs(1);
    cout << min(dp[1][0], dp[1][2]) << '\n';
}

int main(){
    int n;
    while(cin >> n){
        init(n);
        sol();
        cin >> n;
        if(n == -1)break;
    }
}