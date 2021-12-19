#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP  make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
vector<int> v, mv;
int main()
{
    IOS;
    LL n, k;
    cin >> n >> k;
    v.resize(n + 1, 0);
    mv.resize(n + 1, 0);
    int ans = 0;
    FOR(i, 1, n + 1)
    {
        cin >> v[i];
    }
    FORD(i, n, 0)
    {
        if(i + v[i] > n)
        {
            mv[i] = 1;
        }
        else
        {
            mv[i] = mv[i + v[i]] + 1;
        }
        // cout << i << ' ' << mv[i] << " \n";
        if(mv[i] <= k)
        {
            ++ans;
        }
    }
    cout << ans << '\n';
}
