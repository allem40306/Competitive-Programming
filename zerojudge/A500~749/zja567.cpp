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

struct Work
{
    int d, p;
    bool operator<(const Work &rhs) const { return p > rhs.p; }
};

int main()
{
    IOS;
    int n;
    Work a[100005];
    bitset<100005> ok;
    while (cin >> n)
    {
        ok.reset();
        for (int i = 0; i < n; ++i)
            cin >> a[i].d >> a[i].p;
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = a[i].d;
            while (j--)
                if (!ok[j])
                {
                    ans += a[i].p;
                    ok[j] = true;
                    break;
                }
        }
        cout << ans << '\n';
    }
}
