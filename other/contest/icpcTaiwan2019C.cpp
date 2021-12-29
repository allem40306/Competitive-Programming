#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n;
    int a[100];
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    bool ok = true;
    FOR(i, 0, n) FOR(j, 0, n) FOR(k, 0, n)
    {
        if (i == j || i == k || j == k)
            continue;
        if ((a[i] - a[j]) % a[k])
            ok = false;
    }
    if (ok)
        cout << "yes\n";
    else
        cout << "no\n";
}
