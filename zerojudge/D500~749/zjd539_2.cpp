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
const int MXN = 500005;
const int LOG = 20;
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
int sp[LOG][MXN];
int p2[LOG], lg2[MXN];

void build()
{
    p2[0] = 1;
    lg2[1] = 0;
    lg2[2] = 1;
    FOR(i, 1, LOG) p2[i] = p2[i - 1] << 1;
    FOR(i, 3, MXN) lg2[i] = lg2[(i >> 1)] + 1;
}

int main()
{
    IOS;
    build();
    int n, q;
    cin >> n;
    FOR(i, 0, n) cin >> sp[0][i];
    FOR(i, 1, LOG) for (int j = 0; j + p2[i] - 1 < n; ++j)
    {
        sp[i][j] = max(sp[i - 1][j], sp[i - 1][j + p2[i - 1]]);
    }
    cin >> q;
    FOR(i, 0, q)
    {
        int L, R;
        cin >> L >> R;
        if (L > R)
            swap(L, R);
        --L;
        --R;
        int lg = lg2[R - L + 1];
        cout << max(sp[lg][L], sp[lg][R - p2[lg] + 1]) << '\n';
    }
}
