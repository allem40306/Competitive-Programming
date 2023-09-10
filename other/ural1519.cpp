#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
using LL = long long;
const int MXN = 20;
const int MXS = 3e5 + 5;
const int MOD = 3e5;
int cur, las;
int bit[MXN], dpCnt[2], state[MXS], stCnt;
struct DP
{
    int st;
    LL val;
} dp[2][MXS];
struct Edge
{
    int to, nxt;
} e[MXS];

void insert(int st, LL val)
{
    // cout << st << ' ' << val << '\n';
    int p = st % MOD;
    for (int i = state[p]; i; i = e[i].nxt)
        if (dp[cur][e[i].to].st == st)
        {
            dp[cur][e[i].to].val += val;
            return;
        }
    ++dpCnt[cur];
    e[++stCnt].to = dpCnt[cur];
    e[stCnt].nxt = state[p];
    state[p] = stCnt;
    dp[cur][dpCnt[cur]].st = st;
    dp[cur][dpCnt[cur]].val = val;
}

int main()
{
    int a[MXN][MXN] = {};
    int n, m;
    int ex = 0, ey = 0;
    LL ans = 0;
    cin >> n >> m;
    string s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        for (int j = 0; j < m; ++j)
        {
            if (s[j] == '.')
            {
                a[i][j + 1] = 1;
                ex = i;
                ey = j + 1;
            }
        }
    }
    for (int i = 1; i < MXN; ++i)
        bit[i] = (i << 1);
    cur = 0;
    dpCnt[cur] = 1;
    dp[cur][1].st = 0;
    dp[cur][1].val = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= dpCnt[cur]; ++j)
            dp[cur][j].st <<= 2;
        for (int j = 1; j <= m; ++j)
        {
            // cout << "(i,j): " << i << ' ' << j << '\n';
            stCnt = 0;
            memset(state, 0, sizeof(state));
            las = cur;
            cur ^= 1;
            dpCnt[cur] = 0;
            for (int k = 1; k <= dpCnt[las]; ++k)
            {
                int st = dp[las][k].st;
                LL val = dp[las][k].val;
                int down = (st >> bit[j - 1]) % 4;
                int right = (st >> bit[j]) % 4;
                // cout << st << ' ' << down << ' ' << right << '\n';
                if (!a[i][j])
                {
                    if (!down && !right)
                    {
                        insert(st, val);
                        continue;
                    }
                }
                else if (!down && !right)
                {
                    if (a[i][j + 1] && a[i + 1][j])
                        insert(st + (1 << bit[j - 1]) + ((1 << bit[j]) << 1),
                               val);
                }
                else if (!down && right)
                {
                    if (a[i][j + 1])
                        insert(st, val);
                    if (a[i + 1][j])
                        insert(st - right * (1 << bit[j]) +
                                   right * (1 << bit[j - 1]),
                               val);
                }
                else if (down && !right)
                {
                    if (a[i + 1][j])
                        insert(st, val);
                    if (a[i][j + 1])
                        insert(st + down * (1 << bit[j]) -
                                   down * (1 << bit[j - 1]),
                               val);
                }
                else if (down == 1 && right == 1)
                {
                    int cnt = 1;
                    for (int x = j + 1; x <= m; ++x)
                    {
                        if ((st >> bit[x]) % 4 == 1)
                            ++cnt;
                        if ((st >> bit[x]) % 4 == 2)
                            --cnt;
                        if (!cnt)
                        {
                            insert(st - (1 << bit[x]) - (1 << bit[j]) -
                                       (1 << bit[j - 1]),
                                   val);
                            break;
                        }
                    }
                }
                else if (down == 2 && right == 2)
                {
                    int cnt = 1;
                    for (int x = j - 2; x >= 0; --x)
                    {
                        if ((st >> bit[x]) % 4 == 1)
                            --cnt;
                        if ((st >> bit[x]) % 4 == 2)
                            ++cnt;
                        if (!cnt)
                        {
                            insert(st + (1 << bit[x]) - ((1 << bit[j]) << 1) -
                                       ((1 << bit[j - 1]) << 1),
                                   val);
                            break;
                        }
                    }
                }
                else if (down == 2 && right == 1)
                {
                    insert(st - ((1 << bit[j - 1]) << 1) - (1 << bit[j]), val);
                }
                else if (down == 1 && right == 2)
                {
                    if (i == ex && j == ey)
                        ans += val;
                }
            }
        }
    }
    cout << ans << '\n';
}
