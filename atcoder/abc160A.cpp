#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const LL MOD = 998244353;
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
    string s;
    cin >> s;
    if (s[2] == s[3] && s[4] == s[5])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
