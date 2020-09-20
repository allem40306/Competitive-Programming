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

bool ok(const string &a, const string &b, int base)
{
    int suma = 0, sumb = 0;
    FOR(i, 0, a.size())
    {
        int tmp = (isalpha(a[i]) ? a[i] - 'A' + 10 : a[i] - '0');
        if (tmp >= base)
        {
            return 0;
        }
        suma = suma * base + tmp;
    }
    FOR(i, 0, b.size())
    {
        int tmp = (isalpha(b[i]) ? b[i] - 'A' + 10 : b[i] - '0');
        if (tmp >= base)
        {
            return 0;
        }
        sumb = sumb * base + tmp;
    }
    return 0 <= suma && suma <= 23 && 0 <= sumb && sumb <= 59;
}

int main()
{
    IOS;
    string s, a, b;
    cin >> s;
    int pos = (int)s.find(':');
    a = s.substr(0, pos);
    b = s.substr(pos + 1);
    if (ok(a, b, 60))
    {
        cout << "-1\n";
        return 0;
    }
    vector<int> ans;
    FOR(i, 0, 60)
    {
        if (ok(a, b, i))
        {
            ans.PB(i);
        }
    }
    if (ans.empty())
    {
        cout << "0\n";
    }
    else
    {
        FOR(i, 0, ans.size())
        {
            cout << ans[i] << " \n"[i == (int)ans.size() - 1];
        }
    }
}
