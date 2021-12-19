#pragma GCC optimize(2)
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 55;
const int MXV = 0;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);
int n, m;
char s[MXN][MXN];
bool vis[MXN][MXN];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
inline bool ok(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
vector<int> ans;

void bfs2(int x, int y)
{
    PII p1, p2;
    p1.Fi = x;
    p1.Se = y;
    queue<PII> q;
    q.push(p1);
    while (!q.empty())
    {
        p1 = q.front();
        q.pop();
        s[p1.Fi][p1.Se] = '*';
        FOR(i, 0, 4)
        {
            p2.Fi = p1.Fi + dir[i][0];
            p2.Se = p1.Se + dir[i][1];
            if (ok(p2.Fi, p2.Se) && s[p2.Fi][p2.Se] == 'X')
            {
                q.push(p2);
            }
        }
    }
}

void bfs(int x, int y)
{
    PII p1, p2;
    p1.Fi = x;
    p1.Se = y;
    queue<PII> q;
    q.push(p1);
    int cnt = 0;
    while (!q.empty())
    {
        p1 = q.front();
        q.pop();
        if (s[p1.Fi][p1.Se] == '.')
        {
            continue;
        }
        if (s[p1.Fi][p1.Se] == 'X')
        {
            bfs2(p1.Fi, p1.Se);
            ++cnt;
        }
        s[p1.Fi][p1.Se] = '.';
        FOR(i, 0, 4)
        {
            p2.Fi = p1.Fi + dir[i][0];
            p2.Se = p1.Se + dir[i][1];
            if (ok(p2.Fi, p2.Se) && s[p2.Fi][p2.Se] != '.')
            {
                q.push(p2);
            }
        }
    }
    ans.push_back(cnt);
}

int main()
{
    int ti = 0;
    while (scanf("%d %d", &m, &n), n || m)
    {
        // cout << n << ':' << m << '\n';
        FOR(i, 0, n) FOR(j, 0, m) { scanf(" %c", &s[i][j]); }
        memset(vis, 0, sizeof(vis));
        ans.clear();
        FOR(i, 0, n) FOR(j, 0, m)
        {
            if (s[i][j] != '.')
            {
                bfs(i, j);
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Throw " << ++ti << '\n';
        FOR(i, 0, ans.size())
        {
            cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        }
        cout << '\n';
    }
}