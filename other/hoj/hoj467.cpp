#include <bits/stdc++.h>
using namespace std;
const int MXN = 2005;

int main()
{
    int T, N, M, P;
    int x[MXN], y[MXN];
    vector<int> v;
    cin >> T;
    while(T--)
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        cin >> N;
        int cntx = 0, cnty = 0;
        for(int i = 0; i != N; ++i)
        {
            cin >> M >> P;
            if(!P)
            {
                ++x[M];
                ++cntx;
            }
            else
            {
                ++y[M];
                ++cnty;
            }
        }
        int ans = 0;
        for(int i = 1000; i <= 2000; ++i)
        {
            x[i] += x[i - 1];
            y[i] += y[i - 1];
        }
        for(int i = 1000; i <= 2000; ++i)
        {
            int ax = x[i] - x[999], ay = y[i] - y[999];
            int bx = x[2000] - x[i], by = y[2000] - y[i];
            if(ax + ay == 0 || bx + by == 0)
            {
                continue;
            }
            ans = max(ans, max(ax + by, ay + bx));
        }
        cout << ans << '\n';
    }
}