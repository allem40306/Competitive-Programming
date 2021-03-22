#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
using namespace std;
using dvt = double;
const dvt INF = 1e20;
const int MXN = 1e5 + 5;
struct dot
{
    dvt x, y;
} p[MXN], tmp[MXN];

bool cmpX(dot a, dot b) { return a.x < b.x; }
bool cmpY(dot a, dot b) { return a.y < b.y; }

dvt getDis(dot a, dot b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

dvt nearestPair(int L, int R)
{
    dvt d = INF;
    if (L == R)
    {
        return d;
    }
    if (L + 1 == R)
    {
        return getDis(p[L], p[R]);
    }
    int M = (L + R) >> 1;
    dvt d1 = nearestPair(L, M);
    dvt d2 = nearestPair(M, R);
    d = min(d1, d2);
    int k = 0;
    for (int i = L; i <= R; ++i)
    {
        if (fabs(p[i].x - p[M].x) <= d)
        {
            tmp[k++] = p[i];
        }
    }
    sort(tmp, tmp + k, cmpY);
    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k && tmp[j].y - tmp[i].y < d; ++j)
        {
            double d3 = getDis(tmp[i], tmp[j]);
            d = min(d, d3);
        }
    }
    return d;
}

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        sort(p, p + n, cmpX);
        dvt res = nearestPair(0, n - 1);
        printf("%.2lf\n", res / 2);
    }
}
