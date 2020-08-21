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

ULL gethash(int L, int R) { return val[R] - val[L - 1] * _pow[R - L + 1]; }

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
        int ans = 0;
        for (int i = 1; i <= L && i + m * L <= sz; ++i)
        {
            // cout << i << ':' << '\n';
            mp.clear();
            for (int j = i; j < i + m * L; j += L)
            {
                ULL tmp = gethash(j, j + L - 1);
                // cout << tmp << '\n';
                mp[tmp]++;
            }
            if ((int)mp.size() == m)
            {
                ++ans;
            }
            for (int j = i; j + m * L + L - 1 <= sz; j += L)
            {
                ULL tmp = gethash(j, j + L - 1);
                --mp[tmp];
                if (mp[tmp] == 0)
                {
                    mp.erase(tmp);
                }
                ++mp[gethash(j + m * L, j + m * L + L - 1)];
                if ((int)mp.size() == m)
                {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}