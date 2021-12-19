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
const int MXV = 1005;
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

bool dfs(int u)
{
    int leaf_cnt = 0; //記錄葉節點個數
    for (auto v:G[u])
    {
        if((int)G[v].size() == 0) // 葉節點
        {
            ++leaf_cnt;
        }else if(!dfs(v)){
            return false;
        }
    }
    return (leaf_cnt >= 3);
}

int main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 2, j; i <= n; ++i)
    {
        cin >> j;
        G[j].emplace_back(i);
    }
    if(dfs(1))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
