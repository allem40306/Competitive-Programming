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
const int MXN = 55;
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
    // IOS;
    int t, ti = 0;
    bitset<MXN> ok[MXN];
    cin >> t;
    while (t--)
    {
        int n;
        string in, out;
        cin >> n >> in >> out;
        cout << "Case #" << ++ti << ": \n";
        FOR(i, 0, n) { ok[i].reset(); }
        FOR(i, 0, n) FOR(j, 0, n)
        {
            if (i == j || (abs(j - i) == 1 && in[j] == 'Y' && out[i] == 'Y'))
            {
                ok[i][j] = true;
            }
        }
        FOR(k, 0, MXN) FOR(i, 0, n) FOR(j, 0, n)
        {
            if (abs(j - i) <= 1 || in[j] != 'Y' || out[i] != 'Y')
            {
                continue;
            }
            if (i - 1 >= 0 && j + 1 < n && ok[i - 1][j] && ok[i][j + 1])
            {
                ok[i][j] = true;
            }
            if (i + 1 < n && j - 1 >= 0 && ok[i + 1][j] && ok[i][j - 1])
            {
                ok[i][j] = true;
            }
        }
        // cout << "Case #" << ++ti << ": \n";
        FOR(i, 0, n) FOR(j, 0, n)
        {
            cout << (ok[i][j] ? 'Y' : 'N');
            if (j == n - 1)
            {
                cout << '\n';
            }
        }
    }
}
