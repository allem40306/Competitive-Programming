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
    int c;
    vector<int> cars;
    cin >> c;
    FOR(ci, 0, c)
    {
        int n, t, m;
        cin >> n >> t >> m;
        cars.resize(m);
        FOR(i, 0, m) { cin >> cars[i]; }
        if (n >= m)
        {
            cout << cars[m - 1] + t << ' ' << 1 << '\n';
        }
        else if (m % n)
        {
            int finalTime = cars[m % n - 1] + 2 * t;
            for (int i = n + m % n - 1; i < m; i += n)
            {
                finalTime = max(finalTime, cars[i]) + 2 * t;
            }
            cout << finalTime - t << ' ' << m / n + 1 << '\n';
        }
        else
        {
            int finalTime = 0;
            for (int i = n - 1; i < m; i += n)
            {
                finalTime = max(finalTime, cars[i]) + 2 * t;
            }
            cout << finalTime - t << ' ' << m / n << '\n';
        }
    }
}
