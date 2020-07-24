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
const int MXN = 40005;
const int MXV = 0;
const ULL MOD = 10009;
const ULL seed = 1313131;
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
int m, sz;
ULL val[MXN], _pow[MXN];
char s[MXN];

map<ULL, int> mp;
int check(int x)
{
    // cout << "test " << x << '\n';
    int res = -1;
    mp.clear();
    FOR(i, x, sz + 1)
    {
        ULL tmp = val[i] - (val[i - x] * _pow[x]);
        ++mp[tmp];
        // cout << i << ' ' << mp[tmp] << '\n';
        if (mp[tmp] >= m)
        {
            res = i - x;
        }
    }
    return res;
}

int main()
{
    _pow[0] = 1;
    FOR(i, 1, MXN) { _pow[i] = _pow[i - 1] * seed; }
    while (scanf("%d", &m), m)
    {
        scanf("%s", s + 1);
        sz = strlen(s + 1);
        val[0] = 0;
        FOR(i, 1, sz + 1) { val[i] = val[i - 1] * seed + (s[i] - 'a'); }
        int L = 1, R = sz;
        int ansLen = -1, ansPos = 0;
        if (check(1) == -1)
        {
            printf("none\n");
            continue;
        }
        while (L <= R)
        {
            int M = (L + R) >> 1;
            int res = check(M);
            // cout << M << ' ' << res << '\n';
            if (res != -1)
            {
                ansLen = M;
                ansPos = res;
                L = M + 1;
            }
            else
            {
                R = M - 1;
            }
        }
        printf("%d %d\n", ansLen, ansPos);
    }
}