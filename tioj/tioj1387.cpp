#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int INF = 1e9;
struct Data{
    int id,val;
};

int main(){
    int n, t;
    int dp[N];
    fill(dp, dp + N, -INF);
    dp[0] = 0;
    cin >> n;
    for(int i = 0, w, m, c; i < n; i++){
        deque<Data> dq[105];
        cin >> w >> m >> c;
        for(int j = 0; j < N; j++){
            if(j < w){
                dq[j].push_back({j,dp[j]});
                continue;
            }
            int id = j % w;
            while(dq[id].front().id + c * w < j)dq[id].pop_front();
            int tmp = dq[id].front().val + (j - dq[id].front().id) / w * m;
            while(!dq[id].empty() && dq[id].back().val + (j - dq[id].back().id) / w * m <= dp[j])
                dq[id].pop_back();
            dq[id].push_back({j,dp[j]});
            dp[j] = max(dp[j], tmp);
        }
    }
    int ans = -INF;
    cin >> t;
    for(int i = 0; i <= t; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}