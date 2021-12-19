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
string keyboard = "!@#$%^&*()QWERTYUIOPASDFGHJKL:ZXCVBNM<>?";
vector<int> dx = {0, -1, 1, 0, 0}, dy = {0, 0, 0, 1, -1};

PII where(char ch)
{
    int pos = (int)keyboard.find(ch);
    // cout << ch << pos << '\n';
    return {pos / 10, pos % 10};
}

int main()
{
    IOS;
    int t;
    cin >> t;
    FOR(ti, 0, t)
    {
        int n;
        char ch;
        string s, ans = "";
        cin >> s >> ch >> n;
        PII cmpPos = where(s[0]);
        PII nowPos = where(ch);
        nowPos.F = (nowPos.F + dx[n] + 4) % 4;
        nowPos.S = (nowPos.S + dy[n] + 10) % 10;
        ans += keyboard[nowPos.F * 10 + nowPos.S];
        FOR(i, 1, s.size())
        {
            PII tmpPos = where(s[i]);
            nowPos.F = (nowPos.F + (tmpPos.F - cmpPos.F) + 4) % 4;
            nowPos.S = (nowPos.S + (tmpPos.S - cmpPos.S) + 10) % 10;
            ans += keyboard[nowPos.F * 10 + nowPos.S];
            cmpPos = tmpPos;
        }
        cout << ans << '\n';
    }
}
