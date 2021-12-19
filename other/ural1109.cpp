#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXV = 1e3 + 5;
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

int n, m, k;
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
    FOR(i, 1, m + 1)
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
    scanf("%d %d %d", &m, &n, &k);
    memset(w, 0, sizeof(w));
    int x, y;
    FOR(i, 1, k + 1)
    {
        scanf("%d %d", &x, &y);
        w[x][y] = 1;
    }
    printf("%d\n", m + n - sol());
}