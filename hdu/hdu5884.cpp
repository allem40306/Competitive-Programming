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
int n;
LL t;

vector<LL> v, w;

bool ok(int x)
{
    w.clear();
    int vi = 0, wi = 0;
    LL sum = 0;
    int LeftNode = (n - 1) % (x - 1);
    if (LeftNode)
    {
        int tmp = 0;
        FOR(i, 0, LeftNode + 1) { tmp += v[vi++]; }
        sum += tmp;
        w.push_back(tmp);
    }
    while (((int)v.size() - vi) + ((int)w.size() - wi) > 1)
    {
        int tmp = 0;
        FOR(i, 0, x)
        {
            if (vi == (int)v.size())
            {
                tmp += w[wi++];
            }
            else if (wi == (int)w.size())
            {
                tmp += v[vi++];
            }
            else if (v[vi] < w[wi])
            {
                tmp += v[vi++];
            }
            else
            {
                tmp += w[wi++];
            }
        }
        sum += tmp;
        w.push_back(tmp);
    }
    // cout << x << ' ' << sum << '\n';
    return sum <= t;
}

int main()
{
    // IOS;
    int t0;
    cin >> t0;
    while (t0--)
    {
        cin >> n >> t;
        v.resize(n);
        FOR(i, 0, n) { cin >> v[i]; }
        sort(v.begin(), v.end());
        int L = 1, R = n, M;
        while (L < R)
        {
            M = (L + R) >> 1;
            if (ok(M))
            {
                R = M;
            }
            else
            {
                L = M + 1;
            }
        }
        cout << L << '\n';
    }
}
