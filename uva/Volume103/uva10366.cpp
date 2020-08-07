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
const int MXN = 1e3 + 5;
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
vector<int> Lhs(MXN), Rhs(MXN);
int L, M, R;
int Lh, Lhi, Rh, Rhi;

int sol()
{
    // cout << Lh << ' ' << Rh << '\n';
    if (Lh == Rh)
    {
        int Lt = 0, Rt = 0;
        for (int i = L, h = Lhs[L]; i > Lhi; --i)
        {
            Lt += h;
            h = max(h, Lhs[i - 1]);
        }
        for (int i = R, h = Rhs[R]; i > Rhi; --i)
        {
            Rt += h;
            h = max(h, Rhs[i - 1]);
        }
        return (Lhi + Rhi + 1) * Lh + min(Lt, Rt) * 2;
    }
    int T = min(Lh, Rh);
    int Lti = 0, Rti = 0;
    while (Lti < L && Lhs[Lti] < T)
    {
        ++Lti;
    }
    while (Rti < R && Rhs[Rti] < T)
    {
        ++Rti;
    }
    int Lt = 0, Rt = 0, t;
    if (Lh < Rh)
    {
        for (int i = L, h = Lhs[L]; i > Lhi; --i)
        {
            Lt += h;
            h = max(h, Lhs[i - 1]);
        }
        for (int i = Rti, h = T; Rhs[i] <= T; ++i)
        {
            Rt += h;
            h = max(h, Rhs[i + 1]);
        }
        t = ((Lt > Rt) ? (Lt + Rt) : (2 * Lt));
    }
    else
    {
        for (int i = R, h = Rhs[R]; i > Rhi; --i)
        {
            Rt += h;
            h = max(h, Rhs[i - 1]);
        }
        for (int i = Lti, h = T; Lhs[i] <= T; ++i)
        {
            Lt += h;
            h = max(h, Lhs[i + 1]);
        }
        t = ((Rt > Lt) ? (Lt + Rt) : (2 * Rt));
    }
    return t + (Rti + Lti + 1) * T;
}

int main()
{
    // IOS;
    int Lx, Rx;
    while (cin >> Lx >> Rx, Lx || Rx)
    {
        L = (-Lx) / 2;
        R = Rx / 2;
        Lh = Rh = 0;
        for (int i = Lx; i < 0; i += 2)
        {
            int xi = (-i) / 2;
            cin >> Lhs[xi];
            if (Lh <= Lhs[xi])
            {
                Lh = Lhs[xi];
                Lhi = xi;
            }
        }
        for (int i = 1; i <= Rx; i += 2)
        {
            int xi = i / 2;
            cin >> Rhs[xi];
            if (Rh < Rhs[xi])
            {
                Rh = Rhs[xi];
                Rhi = xi;
            }
        }
        cout << sol() * 2 << '\n';
    }
}
