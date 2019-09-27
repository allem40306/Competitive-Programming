/*
source: ABC 141 C Attack Survival
*/
#include <bits/stdc++.h>
using namespace std;
const int MXN = 100005;

int main()
{
    int n, k, q;
    int a[MXN] = {};
    cin >> n >> k >> q;
    for(int i = 0, x; i < q; ++i)
    {
        cin >> x;
        ++a[x];
    }
    for(int i = 1; i <= n; ++i)
    {
        cout << (k - (q - a[i]) > 0 ? "Yes\n" : "No\n");
    }
}