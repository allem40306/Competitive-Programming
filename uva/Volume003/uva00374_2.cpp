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

LL f(LL a, LL b, LL c)
{
    if (b < 1)
        return 1;
    LL res = f(a, b >> 1, c);
    if (b & 1)
        return ((res * res) % c * a) % c;
    return (res * res) % c;
}

int main()
{
    IOS;
    LL a, b, c;
    while (cin >> a >> b >> c)
    {
        cout << f(a, b, c) << '\n';
    }
}
