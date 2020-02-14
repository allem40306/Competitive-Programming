#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 2000005;
const int MXV = 0;
#define MP  make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

vector<int> phi(MXN, 0), a(MXN, 0), sum(MXN, 0);

void phi_table(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (phi[i])
            continue;
        for (int j = i; j <= n; j += i)
        {
            if (!phi[j])
                phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}

int main()
{
    IOS;
    phi_table(MXN - 1);
    FOR(i, 2, MXN)
    {
        a[i] = a[phi[i]] + 1;
        sum[i] = sum[i - 1] + a[i];
    }
    int N, m, n;
    cin >> N;
    while(N--)
    {
        cin >> m >> n;
        cout << sum[n] - sum[m - 1] << '\n';
    }
}
