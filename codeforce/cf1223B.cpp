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
const int MXS = 2e6 + 5;
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
    int q;
    char s[MXS];
    scanf("%s", s);
    scanf("%d", &q);
    int len = strlen(s);
    int now = 0;
    FOR(i, 0, q)
    {
        char ch;
        int val;
        scanf(" %c %d", &ch, &val);
        if (ch == 'A')
        {
            printf("%c\n", s[(now + val - 1 + len) % len]);
        }
        else
        {
            now = (now + val) % len;
        }
    }
}
