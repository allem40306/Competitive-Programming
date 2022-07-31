#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int c[N], dp[N][N];

int f(int L, int R)
{
    if (dp[L][R] != -1)
        return dp[L][R];
    if (L == R - 1)
        return dp[L][R] = 0;
    dp[L][R] = INT_MAX;
    for (int i = L + 1; i < R; ++i)
        dp[L][R] = min(dp[L][R], f(L, i) + f(i, R) + (c[R] - c[L]));
    return dp[L][R];
}

int main()
{
    int L, n;
    while (cin >> L, L)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        c[0] = 0;
        c[n + 1] = L;
        memset(dp, -1, sizeof(dp));
        printf("The minimum cutting is %d.\n", f(0, n + 1));
    }
}