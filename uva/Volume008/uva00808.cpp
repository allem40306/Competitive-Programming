#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 15000;
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
struct Loc
{
    int x, y;
    Loc(){};
    Loc(int _x, int _y) : x(_x), y(_y) {}
} p[MXN];

int dx[6] = {-1, -1, 0, 1, 1, 0};
int dy[6] = {0, 1, 1, 0, -1, -1};
int cur = 2, curx = 1, cury = -1;

void f(int dir, int L)
{
    while (L--)
    {
        curx += dx[dir];
        cury += dy[dir];
        p[++cur] = Loc(curx, cury);
    }
}

void build()
{
    p[1] = Loc(0, 0);
    p[2] = Loc(1, -1);
    for (int i = 1; i <= 60; ++i)
    {
        for (int dir = 0; dir < 6; ++dir)
            f(dir, i + (dir == 4));
    }
}

int dist(int a, int b)
{
    int x = p[a].x - p[b].x;
    int y = p[a].y - p[b].y;
    if (x * y < 0)
        return max(abs(x), abs(y));
    else
        return abs(x + y);
}

int main()
{
    IOS;
    build();
    int a, b;
    while (cin >> a >> b, a || b)
    {
        int ans = dist(a, b);
        cout << "The distance between cells " << a << " and " << b << " is "
             << ans << ".\n";
    }
}
