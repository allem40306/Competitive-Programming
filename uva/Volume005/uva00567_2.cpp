#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
const int MXV = 25;

template <typename T> struct FloydWarshall
{
    T d[MXV][MXV];
    void init() { memset(d, 0x3f, sizeof(d)); }
    void floydWarshall(int n)
    {
        for (int k = 1; k <= n; ++k)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
};

int main()
{
    // IOS;
    int t, n, x, y, ti = 1;
    FloydWarshall<int> floydWarshall;
    while (cin >> t)
    {
        floydWarshall.init();
        for (int i = 1; i < 20; i++)
        {
            if (i > 1)
            {
                cin >> t;
            }
            while (t--)
            {
                cin >> x;
                floydWarshall.d[i][x] = floydWarshall.d[x][i] = 1;
            }
        }
        floydWarshall.floydWarshall(20);
        cout << "Test Set #" << ti++ << '\n';
        cin >> n;
        while (n--)
        {
            cin >> x >> y;
            cout << setw(2) << x << " to " << setw(2) << y << ':' << setw(2)
                 << floydWarshall.d[x][y] << '\n';
        }
        cout << '\n';
    }
}