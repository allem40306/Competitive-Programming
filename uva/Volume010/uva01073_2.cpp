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

LL cn4(LL x) { return x * (x - 1) * (x - 2) * (x - 3) / 24; }

int main()
{
    IOS;
    int ti = 0;
    LL n;
    while (cin >> n, n)
    {
        cout << "Case " << ++ti << ": ";
        if (n % 2 || n == 2)
        {
            cout << "0\n";
        }
        else
        {
            int r = (n + 4) / 2;
            cout << cn4(r) + cn4(r - 1) << '\n';
        }
    }
}
