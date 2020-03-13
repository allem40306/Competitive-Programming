/*
source: ABC 157 C Guess The Number
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
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
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n, m;
    int d[5];
    bool ok = true;
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    FOR(i, 0, m)
    {
        int s, c;
        cin >> s >> c;
        if (d[s] != -1 && d[s] != c)
        {
            ok = false;
            break;
        }
        d[s] = c;
    }
    if (ok == false)
    {
        cout << "-1\n";
    }
    else if (n == 1)
    {
        cout << ((d[1] == -1) ? 0 : d[1]) << '\n';
    }
    else
    {
        if (d[1] == 0)
        {
            cout << -1 << '\n';
        }
        else
        {
            FOR(i, 1, n + 1)
            {
                if (d[i] == -1)
                {
                    cout << (i == 1 ? 1 : 0);
                }
                else
                {
                    cout << d[i];
                }
            }
            cout << '\n';
        }
    }
}
