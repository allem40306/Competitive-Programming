#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
struct Data
{
    int d;
    char kind;
    bool operator<(const Data &rhs) const { return d < rhs.d; }
};

int main()
{
    IOS;
    int t;
    vector<Data> v;
    cin >> t;
    FOR(ti, 1, t + 1)
    {
        int n, d;
        cin >> n >> d;
        v.resize(n);
        char ch;
        FOR(i, 0, n) { cin >> v[i].kind >> ch >> v[i].d; }
        sort(v.begin(), v.end());
        int ans = 0, cur = 0;
        int frog[2];
        frog[0] = frog[1] = 0;
        FOR(i, 0, n)
        {
            if (v[i].kind == 'B')
            {
                ans = max({ans, v[i].d - frog[0], v[i].d - frog[1]});
                frog[0] = frog[1] = v[i].d;
            }
            else
            {
                ans = max(ans, v[i].d - frog[cur]);
                frog[cur] = v[i].d;
                cur = 1 - cur;
            }
        }
        ans = max({ans, d - frog[0], d - frog[1]});
        cout << "Case " << ti << ": " << ans << "\n";
    }
}
