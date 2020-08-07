#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const LL INF = 1e18;
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
vector<LL> num;
vector<char> op;

LL calc(LL x, LL y, char ch)
{
    if (ch == '+')
    {
        return x + y;
    }
    return x * y;
}

PLL sol(int L, int R)
{
    // cout << '(' << L << ',' << R << ')' << '\n';
    if (L == R)
    {
        return {num[L], num[L]};
    }
    if (L + 1 == R)
    {
        LL res = calc(num[L], num[R], op[L]);
        return {res, res};
    }
    PLL res;
    res.F = INF;
    res.S = 0;
    FOR(i, L, R)
    {
        PLL tmp1 = sol(L, i);
        PLL tmp2 = sol(i + 1, R);
        // cout << L << ' ' << i << ' ' << tmp1.F << ' ' << tmp1.S << '\n';
        // cout << i + 1 << ' ' << R << ' ' << tmp2.F << ' ' << tmp2.S << '\n';
        res.F = min(res.F, calc(tmp1.F, tmp2.F, op[i]));
        res.S = max(res.S, calc(tmp1.S, tmp2.S, op[i]));
        // cout << res.F << ' ' << res.S << '\n';
    }
    return res;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stringstream ss(s);
        int x;
        char ch;
        ss >> x;
        op.clear();
        num.clear();
        num.push_back(x);
        while (ss >> ch >> x)
        {
            op.push_back(ch);
            num.push_back(x);
        }
        // FOR(i, 0, op.size()) { cout << i << op[i] << '\n'; }
        PLL ans = sol(0, (int)num.size() - 1);
        cout << "The maximum and minimum are " << ans.S << " and " << ans.F
             << ".\n";
    }
}
