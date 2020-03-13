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

struct Data
{
    int t, L, R;
    void read() { cin >> t >> L >> R; }
    bool operator<(const Data &rhs) const { return t < rhs.t; }
};
vector<Data> v;

int main()
{
    IOS;
    int q;
    cin >> q;
    while (q--)
    {
        int t, L, R, now = 0;
        cin >> t >> L;
        R = L;
        v.resize(t);
        FOR(i, 0, t) { v[i].read(); }
        sort(v.begin(), v.end());
        bool ok = true;
        FOR(i, 0, t)
        {
            int disT = abs(v[i].t - now);
            // [L-disT,R+disT]
            int newL = max(L - disT, v[i].L);
            int newR = min(R + disT, v[i].R);
            if (newL > newR)
            {
                ok = false;
                break;
            }
            L = newL;
            R = newR;
            now = v[i].t;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
