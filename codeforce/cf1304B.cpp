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

bool ok(int sz, string &s, string &r)
{
    FOR(i, 0, sz)
    {
        if (s[i] != r[sz - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    IOS;
    int n, m, middleString = -1;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> match(n, -1);
    FOR(i, 0, n) { cin >> s[i]; }
    FOR(i, 0, n)
    {
        if (match[i] != -1)
        {
            continue;
        }
        FOR(j, i + 1, n)
        {
            if (ok(m, s[i], s[j]))
            {
                match[i] = j;
                match[j] = i;
                break;
            }
        }
        if(middleString == -1 && ok(m, s[i], s[i]))
        {
            middleString = i;
        }
    }
    stack<int> choose;
    string ans = "";
    FOR(i, 0, n)
    {
        if(match[i] != -1 && i < match[i])
        {
            ans += s[i];
            choose.push(match[i]);
        }
    }
    if(middleString != -1)
    {
        ans += s[middleString];
    }
    while(!choose.empty())
    {
        int k = choose.top();
        choose.pop();
        ans += s[k];
    }
    cout << (int)ans.size() << '\n';
    cout << ans << '\n';
}
