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
vector<int> a;

bool ok(int x)
{
    for (int i : a)
    {
        if (i % x == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    a.resize(n);
    FOR(i, 0, n) { cin >> a[i]; }
    int i = 2;
    while (!ok(i))
    {
        ++i;
    }
    cout << i << '\n';
}
