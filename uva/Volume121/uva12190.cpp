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

long long bill(long long x)
{
    if (x < 100)
        return 2 * x;
    if (x < 10000)
        return 3 * (x - 100) + 200;
    if (x < 1000000)
        return 5 * (x - 10000) + 29900;
    else
        return 7 * (x - 1000000) + 4979900;
}

int main()
{
    IOS;
    int a, b;
    while (cin >> a >> b, a || b)
    {
        long long tot = 0;
        long long L = 0, R = 1000000000;
        while (L <= R)
        {
            long long M = (L + R) >> 1;
            long long res = bill(M);
            if (res == a)
            {
                tot = M;
                break;
            }
            if (res < a)
                L = M + 1;
            else
                R = M - 1;
        }
        L = 0;
        R = tot;
        while (L <= R)
        {
            long long M = (L + R) >> 1;
            long long res = bill(tot - M) - bill(M);
            if (res == b)
            {
                cout << bill(M) << '\n';
                break;
            }
            if (res < b)
                R = M - 1;
            else
                L = M + 1;
        }
    }
}
