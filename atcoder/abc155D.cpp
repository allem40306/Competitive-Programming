/*
source: AtCoder Beginner Contest 155 D
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const LL INF = 1e18;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define Be begin()
#define En end()
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

int main()
{
    // IOS;
    int n;
    LL k;
    cin >> n >> k;
    vector<LL> v(n);
    FOR(i, 0, n) { cin >> v[i]; }
    sort(v.Be, v.En);
    LL L = -INF, R = INF;
    while (L + 1 < R)
    {
        // cout << L << ' ' << R << '\n';
        LL M = (L + R) >> 1, cnt = 0;
        FOR(i, 0, n)
        {
            if (v[i] < 0)
            {
                int LL = -1, RR = n;
                while (LL + 1 < RR)
                {
                    int MM = (LL + RR) >> 1;
                    (v[i] * v[MM] < M) ? (RR = MM) : (LL = MM);
                }
                cnt += n - RR;
            }
            else
            {
                int LL = -1, RR = n;
                while (LL + 1 < RR)
                {
                    int MM = (LL + RR) >> 1;
                    (v[i] * v[MM] < M) ? (LL = MM) : (RR = MM);
                }
                cnt += RR;
            }
            if (v[i] * v[i] < M)
            {
                --cnt;
            }
        }
        cnt /= 2;
        // cout << M << ' ' << cnt << '\n';
        (cnt < k) ? (L = M) : (R = M);
    }
    cout << L << '\n';
}
