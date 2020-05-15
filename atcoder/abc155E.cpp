/*
source: AtCoder Beginner Contest 155 E
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 1000005;
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
    LL ans = 0;
    string s;   
    vector<LL> n(MXN, 0);
    cin >> s;
    s = '0' + s;
    FOR(i, 0, s.size())
    {
        n[i] = int(s[s.size() - 1 - i] - '0');
    }
    FOR(i, 0, s.size())
    {
        n[i + 1] += n[i] / 10;
        n[i] %= 10;
        if(n[i] > 5 || (n[i] == 5 && n[i + 1] >= 5))
        {
            ans += 10 - n[i];
            n[i] = 0;
            n[i + 1] += 1;
        }
        else
        {
            ans += n[i];
        }
    }
    cout << ans << '\n';
}
