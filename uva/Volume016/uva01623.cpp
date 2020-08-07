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
const int MXN = 1e6 + 5;
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
int r[MXN], ans[MXN], lastRain[MXN];
set<int> noRainDay;

int main()
{
    IOS;
    int z;
    cin >> z;
    while (z--)
    {
        int n, m;
        cin >> n >> m;
        memset(ans, -1, sizeof(ans));
        memset(lastRain, 0, sizeof(lastRain));
        noRainDay.clear();
        FOR(i, 1, m + 1) { cin >> r[i]; }
        bool ok = true;
        FOR(i, 1, m + 1)
        {
            if (r[i] == 0)
            {
                ans[i] = 0;
                noRainDay.insert(i);
                continue;
            }
            auto it = noRainDay.lower_bound(lastRain[r[i]]);
            if (it == noRainDay.end())
            {
                ok = false;
                break;
            }
            ans[*it] = r[i];
            lastRain[r[i]] = i;
            noRainDay.erase(*it);
        }
        if (ok)
        {
            cout << "YES\n";
            bool delimiter = false;
            FOR(i, 1, m + 1)
            {
                if (ans[i] == -1)
                {
                    continue;
                }
                if (delimiter)
                {
                    cout << ' ';
                }
                delimiter = true;
                cout << ans[i];
            }
            cout << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }
}