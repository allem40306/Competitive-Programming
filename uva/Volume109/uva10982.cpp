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
const int MXN = 1e2 + 5;
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
    IOS;
    int t;
    int room[MXN], tmp[2], group[2];
    bool vis[MXN][MXN];
    cin >> t;
    FOR(ti, 1, t + 1)
    {
        int n, m;
        cin >> n >> m;
        memset(vis, 0, sizeof(vis));
        memset(room, -1, sizeof(room));
        FOR(i, 0, m)
        {
            int x, y;
            cin >> x >> y;
            vis[x][y] = vis[y][x] = true;
        }
        int numOfPair = 0;
        group[0] = group[1] = 0;
        FOR(i, 1, n + 1)
        {
            tmp[0] = tmp[1] = 0;
            FOR(j, 1, i)
            {
                if (vis[i][j])
                {
                    ++tmp[room[j]];
                }
            }
            // cout << i << ' ' << tmp[0] << ' ' << tmp[1] << '\n';
            int res = (tmp[0] <= tmp[1]) ? 0 : 1;
            ++group[res];
            numOfPair += tmp[res];
            room[i] = res;
        }
        if (numOfPair <= m / 2)
        {
            cout << "Case #" << ti << ": " << group[0] << "\n";
            bool first = true;
            FOR(i,1,n+1)
            {
                if(room[i]!=0)
                {
                    continue;
                }
                if(!first){
                    cout << ' ';
                }
                first = false;
                cout << i;
            }
            cout << '\n';
        }
        else
        {
            cout << "Case #" << ti << ": Impossible.\n\n";
        }
    }
}
