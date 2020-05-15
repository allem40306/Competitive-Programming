/*
source: AtCoder Beginner Contest 155 B
*/
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

int main()
{
    IOS;
    int n, x;
    cin >> n;
    bool ok = true;
    FOR(i, 0, n)
    {
        cin >> x;
        if (x % 2 == 0 && x % 3 != 0 && x % 5 != 0)
        {
            ok = false;
        }
    }
    if (ok)
    {
        cout << "APPROVED\n";
    }
    else
    {
        cout << "DENIED\n";
    }
}
