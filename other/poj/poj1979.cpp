#pragma GCC optimize(2)
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);
vector<string> room;
int n, m;
int ans;
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y)
{
    // cout << x << ' ' << y << '\n';
    FOR(i, 0, 4)
    {
        int _x = x + d[i][0];
        int _y = y + d[i][1];
        //     cout << _x << '-' << _y << '\n';
        // if (_x >= 0 && _x < n && _y >= 0 && _y < m)
        // {
        //     cout << room[_x][_y] << '\n';
        // }
        if (_x >= 0 && _x < m && _y >= 0 && _y < n && room[_x][_y] == '.')
        {
            room[_x][_y] = '@';
            ++ans;
            dfs(_x, _y);
        }
    }
}

int main()
{
    IOS;
    while (cin >> n >> m, n || m)
    {
        room.resize(m);
        FOR(i, 0, m) { cin >> room[i]; }
        int x = 0, y = 0;
        FOR(i, 0, m) FOR(j, 0, n)
        {
            if (room[i][j] == '@')
            {
                x = i;
                y = j;
            }
        }
        ans = 1;
        // cout << x << ' ' << y << '\n';
        dfs(x, y);
        cout << ans << '\n';
    }
}
