#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MXV = 0;
const ULL MOD = 10009;
const ULL seed = 31;
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
int m, L, sz;
ULL val[MXN], _pow[MXN];
char s[MXN];

map<ULL, int> mp;
int main()
{
    _pow[0] = 1;
    FOR(i, 1, MXN) { _pow[i] = _pow[i - 1] * seed; }
    while (scanf("%d %d", &m, &L) != EOF)
    {
        scanf("%s", s + 1);
        sz = strlen(s + 1);
        val[0] = 0;
        FOR(i, 1, sz + 1) { val[i] = val[i - 1] * seed + (s[i] - 'a'); }
        int ans = 0, mL = m * L;
        FOR(i, 0, L)
        {
            mp.clear();
            for (int j = i + L; j <= sz; j += L)
            {
                // cout << j << '\n';
                ULL tmp = val[j] - val[j - L] * _pow[L];
                if(mp.find(tmp) == mp.end())
                {
                    mp[tmp] = 0;
                }
                ++mp[tmp];
                // cout << j << ": " << tmp;
                if (j > L + mL)
                {
                    ULL tmp2 = val[j - mL] - val[j - mL - L] * _pow[L];
                    --mp[tmp2];
                    if (mp[tmp2] == 0)
                    {
                        mp.erase(tmp2);
                    }
                    // cout << ' ' << tmp2;
                }
                // cout << '\n';
                if ((int)mp.size() == m)
                {
                    // cout << j - mL << ' ' << j << '\n';
                    // for(auto it: mp)
                    // {
                    //     cout << it.first << ':' << it.second << '\n';
                    // }
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}