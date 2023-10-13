#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 105;
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

int main()
{
    IOS;
    int h, w;
    int arr[MXN][MXN];
    int tar = 101, ans = 0;
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
        {
            cin >> arr[i][j];
            tar = min(tar, arr[i][j]);
        }
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
        {
            ans += arr[i][j] - tar;
        }
    cout << ans << '\n';
}
