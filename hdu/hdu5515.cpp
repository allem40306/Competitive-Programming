#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int INF = 1e9;
const int MXN = 3e5 + 5;
const int MXS = 1e7 + 5;
const int MXW = 26;
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
double T, v1, v2, T1, T2;

bool sol()
{
    if (v1 == v2)
    {
        return true;
    }
    if (v1 * v1 * 2 > v2 * v2)
    {
        double L = 0, R = 300, M;
        FOR(i, 0, 150)
        {
            M = (L + R) / 2;
            double d1 = sqrt(300 * 300 + M * M);
            double d2 = 300 + M;
            (d1 / v1 > d2 / v2) ? (L = M) : (R = M);
        }
        double t1 = sqrt(300 * 300 + L * L) / v1 + L / v1 + 2 * T1;
        double t2 = 3 * T2 + T;
        return t1 <= t2;
    }
    if (v1 * 3 > v2)
    {
        double L = 0, R = 300, M;
        FOR(i, 0, 150)
        {
            M = (L + R) / 2;
            double d1 = sqrt(300 * 300 + M * M);
            double d2 = 900 - M;
            (d1 / v1 > d2 / v2) ? (R = M) : (L = M);
        }
        double t1 = sqrt(300 * 300 + L * L) / v1 +
                    sqrt(300 * 300 + (300 - L) * (300 - L)) / v1 + 3 * T1;
        double t2 = 4 * T2 + T;
        return t1 <= t2;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    FOR(i, 1, t + 1)
    {
        scanf("%lf %lf %lf", &T, &v1, &v2);
        T1 = 300 / v1;
        T2 = 300 / v2;
        bool res = sol();
        if(res)
        {
            printf("Case #%d: Yes\n", i);
        }
        else
        {
            printf("Case #%d: No\n", i);
        }
    }
}