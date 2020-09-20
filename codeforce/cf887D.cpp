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
const int MXN = 1e3 + 5;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ans[MXN][MXN];
char s[MXN][MXN];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    FOR(i, 0, n) { scanf("%s", s[i]); }
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    --x1;
    --y1;
    --x2;
    --y2;
    if (s[x1][y1] == '#' || s[x2][y2] == '#')
    {
        printf("-1\n");
        return 0;
    }
    memset(ans, -1, sizeof(ans));
    queue<PII> q;
    q.push({x1, y1});
    ans[x1][y1] = 0;
    while (!q.empty())
    {
        PII cur = q.front();
        q.pop();
        FOR(i, 0, 4)
        {
            int x = cur.Fi;
            int y = cur.Se;
            FOR(j, 0, k)
            {
                x += dir[i][0];
                y += dir[i][1];
                if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#'||ans[x][y] != -1)
                {
                    break;
                }
                if (ans[x][y] == -1)
                {
                    ans[x][y] = ans[cur.Fi][cur.Se] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    if (ans[x2][y2] == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", ans[x2][y2]);
    }
}
