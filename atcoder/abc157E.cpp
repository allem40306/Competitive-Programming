/*
source: ABC 157 E Simple String Queries
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 30;
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
    int n, q;
    string s;
    set<int> alp[MXN];
    cin >> n >> s >> q;
    FOR(i, 0, MXN)
    {
        alp[i].insert(0);
        alp[i].insert(n + 1);
    }
    FOR(i, 0, n) { alp[s[i] - 'a'].insert(i + 1); }
    FOR(i, 0, q)
    {
        int x;
        cin >> x;
        // cout << x << '\n';
        if (x == 2)
        {
            int y, z, ans = 0;
            cin >> y >> z;
            // cout << y << ' ' << z << '\n';
            FOR(j, 0, MXN)
            {

                // cout << j << ' ' << *alp[j].lower_bound(y) << ' '
                //      << k << "\n";
                if (*alp[j].lower_bound(y) <= z)
                {
                    ++ans;
                }
            }
            cout << ans << '\n';
        }
        else
        {
            int y;
            char z;
            cin >> y >> z;
            alp[s[y - 1] - 'a'].erase(y);
            s[y - 1] = z;
            alp[s[y - 1] - 'a'].insert(y);
        }
    }
}
