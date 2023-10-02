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
LL m;
vector<PLL> ans;

LL C(LL n, LL k)
{
    LL res = 1;
    for (LL i = 1; i <= k; ++i)
    {
        if ((res / i) > (m / (n - i + 1)))
            return m + 1;
        res = res * (n - i + 1) / i;
    }
    return res;
}

void sol()
{
    ans.clear();
    for (LL k = 1; k <= 26; ++k) // c(2k,k)<1e15
    {
        LL L = 2 * k - 1, R = m + 1;
        while (L + 1 < R)
        {
            LL Mid = (L + R) >> 1;
            LL res = C(Mid, k);
            if (res == m)
            {
                ans.emplace_back(MP(Mid, k));
                if (Mid != 2 * k)
                    ans.emplace_back(MP(Mid, Mid - k));
                break;
            }
            else if (res < m)
                L = Mid;
            else
                R = Mid;
        }
    }
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m;
        sol();
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i = 0; i < (int)ans.size(); ++i)
            cout << '(' << ans[i].first << ',' << ans[i].second << ')' << " \n"[i == (int)ans.size()-1];
    }
}
