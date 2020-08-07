#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int INF = 1e9;
const int MXN = 1e3 + 5;
const int MXV = 1e5 + 5;
const LL MOD = 10009;
const LL seed = 31;
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
vector<LL> sum(MXN);

inline void update(int x, int v)
{
    for (; x < MXN; x += (x & (-x)))
    {
        sum[x] += v;
    }
}

inline LL query(int x)
{
    LL ans = 0;
    for (; x > 0; x -= (x & (-x)))
    {
        ans += sum[x];
    }
    return ans;
}

int main()
{
    int t, ti = 0;
    scanf("%d", &t);
    while (t--)
    {
        int m, n, k;
        scanf("%d %d %d", &m, &n, &k);
        vector<PII> v(k);
        FOR(i, 0, k) { scanf("%d %d", &v[i].F, &v[i].S); }
        sort(v.begin(), v.end());
        fill(sum.begin(), sum.end(), 0);
        LL ans = 0;
        FOR(i, 0, k)
        {
            ans += i - query(v[i].S);
            update(v[i].S, 1);
        }
        printf("Test case %d: %lld\n", ++ti, ans);
    }
}