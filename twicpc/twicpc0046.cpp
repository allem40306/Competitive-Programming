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

int main()
{
    IOS;
    int a, b, c;
    cin >> a >> b >> c;
    int x = b / 100, y = b / 10 % 10, z = b % 10;
    FOR(i, 0, 10)
    {
        int tmp1 = i * 100 + y * 10 + z;
        int tmp2 = x * 100 + i * 10 + z;
        int tmp3 = x * 100 + y * 10 + i;
        if (i && a * tmp1 == c)
        {
            cout << a << ' ' << tmp1 << '\n';
            return 0;
        }
        if (a * tmp2 == c)
        {
            cout << a << ' ' << tmp2 << '\n';
            return 0;
        }
        if (a * tmp3 == c)
        {
            cout << a << ' ' << tmp3 << '\n';
            return 0;
        }
    }
    cout << c / b << ' ' << b << '\n';
}
