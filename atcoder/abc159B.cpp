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

bool ok(string &s, int L, int R)
{
    while (L <= R)
    {
        if (s[L] != s[R])
        {
            return false;
        }
        ++L;
        --R;
    }
    return true;
}

int main()
{
    IOS;
    string s;
    cin >> s;
    int sz = (int)s.size();
    if (ok(s, 0, sz - 1) && ok(s, 0, (sz - 1) / 2 - 1) &&
        ok(s, (sz + 3) / 2 - 1, sz - 1))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
