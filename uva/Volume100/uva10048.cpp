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
const int MXV = 105;
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
    int v, e, q;
    int ti = 0;
    int w[MXV][MXV];
    while (cin >> v >> e >> q, v || q || e)
    {
        memset(w, 0x3f, sizeof(w));
        for (int i = 1; i < v + 1; ++i)
        {
            for (int j = 1; j < v + 1; ++j)
                w[i][j] = INF;
            w[i][i] = 0;
        }
        for (int i = 0, x, y, z; i < e; ++i)
        {
            cin >> x >> y >> z;
            w[x][y] = w[y][x] = z;
        }
        for (int k = 1; k < v + 1; ++k)
            for (int i = 1; i < v + 1; ++i)
                for (int j = 1; j < v + 1; ++j)
                    w[i][j] = w[j][i] = min(w[i][j], max(w[i][k], w[k][j]));
        if (ti)
            cout << '\n';
        cout << "Case #" << ++ti << '\n';
        for (int i = 0, x, y; i < q; ++i)
        {
            cin >> x >> y;
            if (w[x][y] == INF)
                cout << "no path\n";
            else
                cout << w[x][y] << '\n';
        }
    }
}
