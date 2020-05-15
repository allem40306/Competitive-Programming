#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
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
    int n;
    cin >> n;
    vector<int> v(n, 0), L(n, 0), R(n, 0);
    vector<PII> order(n);
    FOR(i, 0, n)
    {
        cin >> v[i];
        order[i] = {v[i], i};
        L[i] = i - 1;
        R[i] = i + 1;
    }
    sort(order.begin(), order.end());
    int ans = 0;
    FOR(i, 0, n)
    {
        int now = order[i].S;
        if (v[now] == 0)
        {
            continue;
        }
        while (L[now] >= 0 && v[now] >= v[L[now]])
        {
            v[L[now]] = 0;
            ans += v[now];
            L[now] = L[L[now]];
            if (L[now] >= 0)
            {
                R[L[now]] = now;
            }
        }
        while (R[now] < n && v[now] >= v[R[now]])
        {
            v[R[now]] = 0;
            ans += v[now];
            R[now] = R[R[now]];
            if (R[now] < n)
            {
                L[R[now]] = now;
            }
        }
    }
    cout << ans << '\n';
}
