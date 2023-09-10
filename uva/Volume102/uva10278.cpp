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
const int MXV = 505;
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
    int T;
    int dis[MXV][MXV];
    int cur[MXV];
    vector<int> fs;

    cin >> T;
    for (int ti = 0; ti < T; ++ti)
    {
        int f, v;

        fs.clear();

        cin >> f >> v;
        for (int i = 0, tmp; i < f; ++i)
        {
            cin >> tmp;
            fs.PB(tmp);
        }

        string s;
        int x, y, w;

        memset(dis, 0x3f, sizeof(dis));
        for (int i = 1; i < v + 1; ++i)
            dis[i][i] = 0;

        getline(cin, s);
        while (getline(cin, s), s != "")
        {
            stringstream ss(s);
            ss >> x >> y >> w;
            dis[x][y] = dis[y][x] = w;
        }

        for (int k = 1; k < v + 1; ++k)
            for (int i = 1; i < v + 1; ++i)
                for (int j = 1; j < v + 1; ++j)
                    dis[i][j] = dis[j][i] =
                        min(dis[i][j], dis[i][k] + dis[k][j]);

        memset(cur, 0x3f, sizeof(cur));
        for (int i = 1; i < v + 1; ++i)
            for (int j = 0; j < (int)fs.size(); ++j)
                cur[i] = min(cur[i], dis[i][fs[j]]);

        int ans = 1, ansVal = INF;
        for (int i = 1; i < v + 1; ++i)
        {
            int tmp = 0;
            for (int j = 1; j < v + 1; ++j)
                tmp = max(tmp, min(cur[j], dis[i][j]));
            if (tmp < ansVal)
            {
                ans = i;
                ansVal = tmp;
            }
        }

        if (ti)
            cout << '\n';
        cout << ans << '\n';
    }
}
