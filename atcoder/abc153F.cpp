/*
source: ABC 153 F Silver Fox vs Monster
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
LL n, d, a;
vector<int> sum;
vector<PLL> monsters; // (x, h)

LL sol()
{
    LL ans = 0;
    FOR(i, 0, n)
    {
        if (i)
        {
            sum[i] += sum[i - 1];
        }
        monsters[i].S += sum[i];
        if (monsters[i].S <= 0)
        {
            continue;
        }
        int L = i, R = n, R2 = i, M;
        while (L <= R)
        {
            M = (L + R) >> 1;
            if (monsters[i].F + 2 * d >= monsters[M].F)
            {
                R2 = M;
                L = M + 1;
            }
            else
            {
                R = M - 1;
            }
        }
        LL tmp = (monsters[i].S / a);
        if (monsters[i].S % a > 0)
        {
            ++tmp;
        }
        ans += tmp;
        sum[i] -= tmp * a;
        sum[R2 + 1] += tmp * a;
    }
    return ans;
}

int main()
{
    // IOS;
    cin >> n >> d >> a;
    monsters.resize(n);
    sum.resize(n + 5, 0);
    FOR(i, 0, n) { cin >> monsters[i].F >> monsters[i].S; }
    sort(monsters.begin(), monsters.end());
    cout << sol() << '\n';
}
