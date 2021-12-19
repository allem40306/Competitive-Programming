#pragma GCC optimize(2)
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
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
    }
}

int main()
{
    int ti = 0;
    char s[MXN];
    while (scanf("%s", s), strcmp(s, "END"))
    {
        sol(s);
        int mx = 0;
        FOR(i, 0, si)
        {
            // cout << i << ' ' << ma[i] << '\n';
            mx = max(mx, ma[i] - 1);
        }
        cout << "Case " << ++ti << ": " << mx << '\n';
    }
}