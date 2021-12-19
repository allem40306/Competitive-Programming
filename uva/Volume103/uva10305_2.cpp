#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 105;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
vector<int> G[MXV];
vector<int> ans;
int din[MXV]; // 入度

int main()
{
    IOS;
    int n, m;
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i <= n; ++i)
            G[i].clear();
        memset(din, 0, sizeof(din));
        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;
            G[x].emplace_back(y);
            ++din[y];
        }
        ans.clear();
        int ai = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (din[i] == 0)
                ans.emplace_back(i);
        }
        while(ai < (int)ans.size())
        {
            // 拔點
            int u = ans[ai];
            ++ai;
            for(int v: G[u])
            {
                --din[v];
                if(din[v]==0)
                {
                    ans.emplace_back(v);
                }
            }
        }
        // 可以用 queue，但我為了要方便輸出用 vector
        for (int i = 0; i < n;++i)
        {
            cout << ans[i] << " \n"[i == n - 1];
            // " \n"[i == n - 1]: 除了最後一個數字後面輸出換行
            // 其餘數字後面輸出空白，是整潔的寫法
        }
    }
}
