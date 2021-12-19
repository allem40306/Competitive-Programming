#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXV = 3e2 + 5;
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

int p, n;
int Left[MXV];
int w[MXV][MXV];
bitset<MXV> used;

bool match(int i)
{
    FOR(j, 1, n + 1) if (w[i][j] && !used[j])
    {
        used[j] = 1;
        if (!Left[j] || match(Left[j]))
        {
            Left[j] = i;
            return true;
        }
    }
    return false;
}

int sol()
{
    memset(Left, 0, sizeof(Left));
    int ans = 0;
    FOR(i, 1, p + 1)
    {
        used.reset();
        if (match(i))
        {
            ++ans;
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &p, &n);
        memset(w, 0, sizeof(w));
        int x, y;
        FOR(i, 1, p + 1)
        {
            scanf("%d", &x);
            while (x--)
            {
                scanf("%d", &y);
                w[i][y] = 1;
            }
        }
        if (p == sol())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}