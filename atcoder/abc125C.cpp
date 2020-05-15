/*
source: ABC 125 C GCD on blockboard
*/
#include <bits/stdc++.h>
using namespace std;
const int MXN = 100005;
int a[MXN], pre[MXN], pos[MXN];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    pre[1] = a[1];
    pos[n] = a[n];
    for(int i = 2; i <= n; ++i)
    {
        pre[i] = __gcd(pre[i - 1], a[i]);
    }
    for(int i =n - 1; i > 1; --i)
    {
        pos[i] = __gcd(pos[i + 1], a[i]);
    }
    int ans = max(pre[n - 1], pos[2]);
    for(int i = 2; i != n; ++i)
    {
        ans = max(ans, __gcd(pre[i - 1], pos[i + 1]));
    }
    cout << ans << '\n';
}