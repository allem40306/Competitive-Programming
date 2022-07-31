#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 105;
const int MXV = 0;
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
int a[MXN], d[MXN];

void f(int L, int R, int depth) // [L,R]
{
    if (L > R)
    {
        return;
    }
    int mxPos = L;
    FOR(i, L, R + 1)
    {
        if (a[i] > a[mxPos])
            mxPos = i;
    }
    d[mxPos] = depth;
    f(L, mxPos - 1, depth + 1); // left
    f(mxPos + 1, R, depth + 1); // right
    return;
}

int main()
{
    IOS;
    int t, n;
    cin >> t;
    FOR(ti, 0, t)
    {
        cin >> n;
        FOR(i, 0, n) cin >> a[i];
        f(0, n - 1, 0);
        FOR(i, 0, n) cout << d[i] << " \n"[i == n - 1];
    }
}
