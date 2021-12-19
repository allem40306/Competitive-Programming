#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL extgcd(LL a,LL b,LL &x,LL &y){
    LL d=a;
    if(b){d=extgcd(b,a%b,y,x),y-=(a/b)*x;}
    else x=1,y=0;
    return d;
}//ax+by=1 ax同餘 1 mod b

int main(){
    int t;
    LL a, b, c, k;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> k;
        k = (1LL << k);
        if(a == b){
            cout << "0\n";  
            continue;
        }
        if(c == 0){
            cout << "FOREVER\n";
            continue;
        }
        LL x, y;
        LL G = extgcd(c, k, x, y);
        if((b - a) % G){
            cout << "FOREVER\n";
            continue;
        }
        c /= G; k /= G;
        x *= (b - a) / G; y *= (b - a) / G;
        if(x < 0){
            x += (-x - 1 + k) / k * k;
        }
        x -= x / k * k;
        cout << x << '\n';
    }
}