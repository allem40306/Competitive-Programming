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
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct Loc
{
    int x, y;
    Loc(int x, int y) : x(x), y(y) {}
};

int r, c;
int fire[MXN][MXN], ans[MXN][MXN];
queue<Loc> q;

void clearQueue()
{
    while (!q.empty())
        q.pop();
}

int bfs(int sx, int sy)
{
    while (!q.empty())
    {
        Loc cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int x = cur.x + d[i][0];
            int y = cur.y + d[i][1];
            if (x < 0 || x >= r || y < 0 || y >= c || fire[x][y] != INF)
                continue;
            fire[x][y] = fire[cur.x][cur.y] + 1;
            q.push(Loc(x, y));
        }
    }
    clearQueue();
    memset(ans, 0, sizeof(ans));
    q.push(Loc(sx, sy));
    ans[sx][sy] = 1;
    while (!q.empty())
    {
        Loc cur = q.front();
        q.pop();
        if (cur.x == 0 || cur.x == r - 1 || cur.y == 0 || cur.y == c - 1)
            return ans[cur.x][cur.y];
        for (int i = 0; i < 4; ++i)
        {
            int x = cur.x + d[i][0];
            int y = cur.y + d[i][1];
            if (x < 0 || x >= r || y < 0 || y >= c || ans[x][y] != 0 ||
                ans[cur.x][cur.y] + 1 >= fire[x][y])
                continue;
            ans[x][y] = ans[cur.x][cur.y] + 1;
            q.push(Loc(x, y));
        }
    }
    return -1;
}

int main()
{
    IOS;
    int T;
    char ch;
    cin >> T;
    while (T--)
    {
        cin >> r >> c;
        memset(fire, 0, sizeof(fire));
        clearQueue();
        int x, y;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                fire[i][j] = INF;
                cin >> ch;
                if (ch == '#')
                    fire[i][j] = 0;
                else if (ch == 'F')
                {
                    q.push(Loc(i, j));
                    fire[i][j] = 1;
                }
                else if (ch == 'J')
                {
                    x = i;
                    y = j;
                }
            }
        }

        int res = bfs(x, y);
        if (res == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << res << '\n';
    }
}
