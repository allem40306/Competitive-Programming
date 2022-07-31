#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 1e5 + 5;
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
vector<int> v(MXN);

bool f(int k)
{
    for (int i = 1; i <= n; ++i)
    {
        if (v[i] - v[i - 1] > k)
            return false;
        if (v[i] - v[i - 1] == k)
            --k;
    }
    return true;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    v[0] = 0;
    for (int ti = 1; ti <= t; ++ti)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> v[i];
        int L = 1, R = v[n], ans = 0;
        while (L <= R)
        {
            int M = (L + R) >> 1;
            if (f(M))
            {
                ans = M;
                R = M - 1;
            }
            else
                L = M + 1;
        }
        cout << "Case " << ti << ": " << ans << '\n';
    }
}
