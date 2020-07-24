#pragma GCC optimize(2)
#include <iostream>
#include <vector>
using namespace std;
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
    cin.tie(NULL);                                                          \
    cout.tie(NULL);                                                         \
    ios_base::sync_with_stdio(false);
int n, m;
int ans;
vector<int> v(10);

void dfs(int _m, int _n)
{
    // cout << _m << ' ' << _n << '\n';
    if (_n == n)
    {
        return;
    }
    if (_m == m)
    {
        ++ans;
        return;
    }
    if (_n == 0 || v[_n] < v[_n - 1])
    {
        ++v[_n];
        dfs(_m + 1, _n);
        --v[_n];
    }
    dfs(_m, _n + 1);
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        ans = 0;
        dfs(0, 0);
        cout << ans << '\n';
    }
}
