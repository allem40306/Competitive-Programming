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

int main()
{
    IOS;
    int n;
    vector<PII> v;
    cin >> n;
    FOR(i, 1, n + 1)
    {
        int x;
        cin >> x;
        v.PB({x, i});
    }
    sort(v.begin(), v.end());
    cout << (n + 1) / 2 << '\n';
    bool delimiter = false;
    for (int i = 0; i < n; i += 2)
    {
        if (delimiter)
        {
            cout << ' ';
        }
        delimiter = true;
        cout << v[i].S;
    }
    cout << '\n';
    cout << n / 2 << '\n';
    delimiter = false;
    for (int i = 1; i < n; i += 2)
    {
        if (delimiter)
        {
            cout << ' ';
        }
        delimiter = true;
        cout << v[i].S;
    }
    cout << '\n';
}
