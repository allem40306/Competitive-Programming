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
vector<int> v;

int ansp, ansv;
void build(int L, int R)
{
    // cout << L << ' ' << R << '\n';
    int Lroot = 0;
    for (; Lroot < R; ++Lroot)
    {
        if (v[Lroot] >= v[R])
        {
            break;
        }
    }
    if (Lroot < R)
    {
        build(Lroot, R - 1);
    }
    if (L < Lroot)
    {
        build(L, Lroot - 1);
    }
    cout << v[R] << '\n';
}

int main()
{
    IOS;
    int n;
    cin >> n;
    v.resize(n);
    FOR(i, 0, n) { cin >> v[i]; }
    build(0, n - 1);
}
