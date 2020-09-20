#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
    LL a, b, c, ans = 0;
    cin >> a >> b >> c;
    while(c >= a)
    {
        LL tmp = min(7LL,c/a);
        c -= tmp * a;
        c -= b;
        ans += tmp;
    }
    if(c>0)
    {
        ++ans;
    }
    cout << ans << '\n';
}