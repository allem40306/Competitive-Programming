#pragma GCC optimize(2)
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int MXN = 1e6 + 5;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);
char ss[2 * MXN];
int ma[2 * MXN];
int si;

void sol(char *s)
{
    int sz = strlen(s);
    si = 0;
    ss[si++] = '$';
    ss[si++] = '#';
    FOR(i, 0, sz)
    {
        ss[si++] = s[i];
        ss[si++] = '#';
    }
    // printf("%s\n", ss);
    int mx = 0, id = 0;
    FOR(i, 0, si)
    {
        if (mx > i)
        {
            ma[i] = min(ma[2 * id - i], mx - i);
        }
        else
        {
            ma[i] = 1;
        }
        while (ss[i + ma[i]] == ss[i - ma[i]])
        {
            ++ma[i];
        }
        if (i + ma[i] > mx)
        {
            id = i;
            mx = i + ma[i];
        }
        // cout << i << ' ' << ma[i] << '\n';
    }
}

int val[30], sum[MXN];
int main()
{
    int t;
    char s[MXN];
    cin >> t;
    while (t--)
    {
        FOR(i, 0, 26) { cin >> val[i]; }
        scanf("%s", s);
        sol(s);
        int ans = 0, sz = strlen(s);
        FOR(i, 0, sz)
        {
            sum[i] = val[s[i] - 'a'];
            if (i > 0)
            {
                sum[i] += sum[i - 1];
            }
        }
        FOR(i, 0, sz - 1)
        {
            int tmp = 0;
            int len1 = i + 1, len2 = sz - len1;
            int mid, _ma;
            if (len1 % 2)
            {
                mid = len1 / 2;
                _ma = ma[(mid << 1) + 2];
            }
            else
            {
                mid = len1 / 2 - 1;
                _ma = ma[(mid << 1) + 3];
            }
            if (_ma - 1 == len1)
            {
                tmp += sum[len1 - 1];
            }

            if (len2 % 2)
            {
                mid = len2 / 2 + len1;
                _ma = ma[(mid << 1) + 2];
            }
            else
            {
                mid = len2 / 2 - 1 + len1;
                _ma = ma[(mid << 1) + 3];
            }
            if (_ma - 1 == len2)
            {
                tmp += sum[sz - 1] - sum[len1 - 1];
            }
            ans = max(ans, tmp);
        }
        cout << ans << '\n';
    }
}