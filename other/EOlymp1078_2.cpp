#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 1e9;
const int MXN = 2e6 + 5;
const int MXV = 0;
const LL MOD = 10009;
const LL K = 131;
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
LL val[MXN];
char s[MXN];

LL pow2(LL x, LL y)
{
    LL res = 1;
    while (y)
    {
        if (y & 1)
        {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

bool ok(int len, int sz)
{
    LL _pow = pow2(K, (LL)len);
    for (int i = (len << 1); i <= sz; i += len)
    {
        // cout << len << ' ' << i << ' '
        //      << (val[i] - (val[i - len] * _pow) % MOD + MOD) << ' ' <<
        //      val[len]
        //      << '\n';
        if ((val[i] - (val[i - len] * _pow) % MOD + MOD) % MOD != val[len])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    while (scanf("%s", s + 1) != EOF)
    {
        int sz = strlen(s + 1);
        FOR(i, 1, sz + 1) { val[i] = (val[i - 1] * K + s[i]) % MOD; }
        FOR(i, 1, sz + 1)
        {
            if (sz % i == 0 && ok(i, sz))
            {
                cout << sz / i << '\n';
                break;
            }
        }
    }
}