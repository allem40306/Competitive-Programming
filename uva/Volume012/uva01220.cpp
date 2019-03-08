#include <bits/stdc++.h>
using namespace std;
const int N = 205;
map<string, int>tb;
vector<int>G[N];
int dp[2][N]; // [0] not choose [1] choose
bitset<N> uni[2]; //unique

void init(int n){
    int tot = 0;
    string s, t;
    memset(dp, 0,sizeof(dp));
    uni[0].set(); uni[1].set();
    tb.clear();
    for(int i = 1; i <= n; i++)G[i].clear();
    cin >> s;
    tb[s] = ++tot;
    while(--n){
        cin >> s >> t;
        if(tb.find(s) == tb.end())tb[s] = ++tot;
        if(tb.find(t) == tb.end())tb[t] = ++tot;
        G[tb[t]].push_back(tb[s]);
    }
}

void dfs(int s){
    // cout << "de:" << s << '\n';
    if(!G[s].size()){
        dp[0][s] = 0;
        dp[1][s] = 1;
        return;
    }
    for(int it: G[s]){
        dfs(it);
        
        dp[1][s] += dp[0][it];
        if(!uni[0][it])uni[1][s] = false;

        dp[0][s] += max(dp[0][it], dp[1][it]);
        if(dp[0][it] > dp[1][it]){
            if(!uni[0][it])uni[0][s] = false;
        }else{
            if(dp[0][it] == dp[1][it] || !uni[1][it])uni[0][s] = false;
        }
    }
    dp[1][s]++;
}

int main(){
    int n;
    while(cin >> n, n){
        init(n);
        dfs(1);
        // cout << "de:" << dp[0][1] << ' ' << dp[1][1] << '\n';
        cout << max(dp[0][1], dp[1][1]) << ' ';
        if(dp[0][1] == dp[1][1] ){
            cout << "No\n";
        }else if(dp[0][1] > dp[1][1]){
            cout << (uni[0][1] ? "Yes\n" : "No\n");
        }else{
            cout << (uni[1][1] ? "Yes\n" : "No\n");
        }
    }
}