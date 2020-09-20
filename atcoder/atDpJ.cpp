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
const int MXN = 3e2 + 5;
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
bool vis[MXN][MXN][MXN];
double ans[MXN][MXN][MXN];

double dfs(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0)
    {
        return 0.0;
    }
    if (x == 0 && y == 0 && z == 0)
    {
        return 0.0;
    }
    if (vis[x][y][z])
    {
        return ans[x][y][z];
    }
    vis[x][y][z] = true;
    double &res = ans[x][y][z];
    double f = (double)(n - x - y - z) / n;
    res = dfs(x - 1, y, z) * ((double)x / n) +
          dfs(x + 1, y - 1, z) * ((double)y / n) +
          dfs(x, y + 1, z - 1) * ((double)z / n) + 1.0;
    res /= (1.0 - f);
    return res;
}

int main()
{
    IOS;
    int x = 0, y = 0, z = 0;
    cin >> n;
    FOR(i, 0, n)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 1)
        {
            ++x;
        }
        else if (tmp == 2)
        {
            ++y;
        }
        else if (tmp == 3)
        {
            ++z;
        }
    }
    cout << fixed << setprecision(8) << dfs(x, y, z);
}
