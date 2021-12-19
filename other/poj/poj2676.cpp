#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 105;
const int MXV = 105;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
int a[MXN];
bool ok;
bool used[3][15][15];

void dfs(int x)
{
    if (x == 81)
    {
        FOR(i, 0, 9)
        {
            FOR(j, 0, 9) { cout << a[i * 9 + j]; }
            cout << '\n';
        }
        ok = true;
        return;
    }
    if (a[x] != 0)
    {
        dfs(x + 1);
        return;
    }
    FOR(i, 1, 9 + 1)
    {
        if (used[0][x / 9][i] || used[1][x % 9][i] ||
            used[2][x / 9 / 3 * 3 + x % 9 / 3][i])
        {
            continue;
        }
        used[0][x / 9][i] = used[1][x % 9][i] =
            used[2][x / 9 / 3 * 3 + x % 9 / 3][i] = true;
        a[x] = i;
        dfs(x + 1);
        if (ok)
        {
            return;
        }
        a[x] = 0;
        used[0][x / 9][i] = used[1][x % 9][i] =
            used[2][x / 9 / 3 * 3 + x % 9 / 3][i] = false;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(used, 0, sizeof(used));
        ok = false;
        FOR(i, 0, 81)
        {
            char ch;
            scanf(" %c", &ch);
            a[i] = ch - '0';
            if (a[i])
            {
                used[0][i / 9][a[i]] = used[1][i % 9][a[i]] =
                    used[2][i / 9 / 3 * 3 + i % 9 / 3][a[i]] = true;
            }
        }
        dfs(0);
    }
}