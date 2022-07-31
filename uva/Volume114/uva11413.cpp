#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 1005;
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
vector<long long> v(MXN);
int n, m;

bool f(long long x)
{
    int idx = 0;
    for (int i = 0; i < m; ++i)
    {
        long long cur = 0;
        while (idx < n && cur + v[idx] <= x)
        {
            cur += v[idx];
            ++idx;
        }
    }
    return idx == n;
}

int main()
{
    IOS;
    while (cin >> n >> m)
    {
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
            sum += v[i];
        }
        long long L = 0, R = sum, ans = 0;
        while (L <= R)
        {
            int M = (L + R) >> 1;
            if (f(M))
            {
                R = M - 1;
                ans = M;
            }
            else
                L = M + 1;
        }
        cout << ans << '\n';
    }
}
