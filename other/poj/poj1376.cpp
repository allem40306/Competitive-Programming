#pragma GCC optimize(2)
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>


using namespace std;
const int INF = 1e9;
const int MXN = 55;
const int MXV = 1e4 + 5;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
struct State
{
    int x, y, dir;
    int step;
    State() {}
    State(int _x, int _y, int _dir, int _step)
        : x(_x), y(_y), dir(_dir), step(_step)
    {
    }
};
bool isBlock[MXN][MXN];
int pos[4][5][3] = {{{0, 0, 1}, {0, 0, -1}, {-1, 0, 0}, {-2, 0, 0}, {-3, 0, 0}},
                    {{0, 0, 1}, {0, 0, -1}, {0, -1, 0}, {0, -2, 0}, {0, -3, 0}},
                    {{0, 0, 1}, {0, 0, -1}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}},
                    {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, 2, 0}, {0, 3, 0}}};

queue<State> q;
int m, n;
int ans[MXN][MXN][4];
int bfs(int sx, int sy, int ex, int ey, int dir)
{
    memset(ans, -1, sizeof(ans));
    while (!q.empty())
    {
        q.pop();
    }
    q.push(State(sx, sy, dir, 0));
    ans[sx][sy][dir] = 0;
    while (!q.empty())
    {
        State cur = q.front();
        assert(isBlock[cur.x][cur.y] == 0);
        // cout << cur.x << ' ' << cur.y << ' ' << cur.dir << ' ' << cur.step
        //      << '\n';
        q.pop();
        if (cur.x == ex && cur.y == ey)
        {
            return cur.step;
        }
        FOR(i, 0, 5)
        {
            int x = cur.x + pos[cur.dir][i][0], y = cur.y + pos[cur.dir][i][1],
                dir = (cur.dir + pos[cur.dir][i][2] + 4) % 4;
            // cout << x << ' ' << y << ' ' << dir << '\n';
            if (x <= 0 || x >= m || y <= 0 || y >= n || isBlock[x][y])
            {
                break;
            }
            if (ans[x][y][dir] == -1 || ans[x][y][dir] > cur.step + 1)
            {
                ans[x][y][dir] = cur.step + 1;
                q.push(State(x, y, dir, cur.step + 1));
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d %d", &m, &n), m || n)
    {
        memset(isBlock, 0, sizeof(isBlock));
        FOR(i, 1, m + 1) FOR(j, 1, n + 1)
        {
            int tmp;
            scanf("%d", &tmp);
            if (tmp == 1)
            {
                isBlock[i - 1][j - 1] = isBlock[i - 1][j] = isBlock[i][j - 1] =
                    isBlock[i][j] = 1;
            }
        }
        int sx, sy, ex, ey, dir = -1;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        char s[10];
        scanf("%s", s);
        if (s[0] == 'n')
        {
            dir = 0;
        }
        else if (s[0] == 'w')
        {
            dir = 1;
        }
        else if (s[0] == 's')
        {
            dir = 2;
        }
        else if (s[0] == 'e')
        {
            dir = 3;
        }
        printf("%d\n", bfs(sx, sy, ex, ey, dir));
        // FOR(i, 1, m + 1) FOR(j, 1, n + 1)
        // {
        //     cout << '(';
        //     FOR(k, 0, 4) cout << setw(2) << ans[i][j][k] << ",)"[k == 3];
        //     cout << " \n"[j == n];
        // }
    }
}