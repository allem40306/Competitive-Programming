#pragma GCC optimize(2)
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
const int MXN = 25;
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
bool vis[MXN][MXN][4], vis2[MXN][MXN];
PII S, T, B;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
string dirs = "nsew";
struct Box
{
    int x, y, sx, sy;
    string ans;
    void setVal(int _x, int _y, int _sx, int _sy, string _ans)
    {
        x = _x;
        y = _y;
        sx = _sx;
        sy = _sy;
        ans = _ans;
    }
} b1, b2;
struct People
{
    int x, y;
    string ans;
    void setVal(int _x, int _y, string _ans)
    {
        x = _x;
        y = _y;
        ans = _ans;
    }
} p1, p2;
inline bool ok(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

bool bfs2(int fx, int fy, int bx, int by, int px, int py)
{
    // cout << fx << ' ' << fy << ' ' << bx << ' ' << by << ' ' << px << ' ' <<
    // py
    //      << '\n';
    if (!ok(fx, fy) || s[fx][fy] == '#')
    {
        return false;
    }
    queue<People> q;
    memset(vis2, 0, sizeof(vis2));
    vis2[px][py] = vis2[bx][by] = true;
    p1.setVal(px, py, "");
    q.push(p1);
    while (!q.empty())
    {
        p1 = q.front();
        q.pop();
        if (p1.x == fx && p1.y == fy)
        {
            return true;
        }
        FOR(i, 0, 4)
        {
            p2.x = p1.x + dir[i][0];
            p2.y = p1.y + dir[i][1];
            if (ok(p2.x, p2.y) && !vis2[p2.x][p2.y] && s[p2.x][p2.y] != '#')
            {
                p2.ans = p1.ans + dirs[i];
                vis2[p2.x][p2.y] = 1;
                q.push(p2);
            }
        }
    }
    return false;
}

bool bfs1()
{
    memset(vis, 0, sizeof(vis));
    queue<Box> q;
    b1.setVal(B.Fi, B.Se, S.Fi, S.Se, "");
    q.push(b1);
    while (!q.empty())
    {
        b1 = q.front();
        q.pop();
        if (b1.x == T.Fi && b1.y == T.Se)
        {
            cout << b1.ans << '\n';
            return true;
        }
        FOR(i, 0, 4)
        {
            b2.x = b1.x + dir[i][0];
            b2.y = b1.y + dir[i][1];
            if (!ok(b2.x, b2.y) || vis[b2.x][b2.y][i] || s[b2.x][b2.y] == '#')
            {
                continue;
            }
            if (bfs2(b2.x - 2 * dir[i][0], b2.y - 2 * dir[i][1], b1.x, b1.y,
                     b1.sx, b1.sy))
            {
                // cout << b2.x << ' ' << b2.y << '\n';
                b2.setVal(b2.x, b2.y, b1.x, b1.y, b1.ans + p1.ans);
                b2.ans += toupper(dirs[i]);
                vis[b2.x][b2.y][i] = true;
                q.push(b2);
            }
        }
    }
    cout << "Impossible.\n";
    return false;
}

int main()
{
    int ti = 0;
    while (scanf("%d %d", &n, &m), n || m)
    {
        FOR(i, 0, n) FOR(j, 0, m)
        {
            scanf(" %c", &s[i][j]);
            if (s[i][j] == 'S')
            {
                S.Fi = i;
                S.Se = j;
            }
            if (s[i][j] == 'B')
            {
                B.Fi = i;
                B.Se = j;
            }
            if (s[i][j] == 'T')
            {
                T.Fi = i;
                T.Se = j;
            }
        }
        cout << "Maze #" << ++ti << '\n';
        bfs1();
        cout << '\n';
    }
}