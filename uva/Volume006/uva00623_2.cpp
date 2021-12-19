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
int ans[1500][10000];

void build()
{
    ans[1][0] = 1;
    FOR(i, 2, 1500)
    {
        FOR(j, 0, 10000)
        {
            ans[i][j] = ans[i - 1][j] * i;
            if (j)
            {
                ans[i][j] += ans[i][j - 1] / 10;
                ans[i][j - 1] %= 10;
            }
        }
    }
}

int main()
{
    IOS;
    build();
    int n;
    while (cin >> n)
    {
        cout << n << "!\n";
        if(n==0)
            n = 1;
        int pos = 10000 - 1;
        while (ans[n][pos] == 0)
        {
            --pos;
        }
        while (pos >= 0)
        {
            cout << ans[n][pos];
            --pos;
        }
        cout << '\n';
    }
}
