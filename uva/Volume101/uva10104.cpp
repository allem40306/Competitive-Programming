#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL extgcd(LL a, LL b, LL &x, LL &y){
    LL d = a;
    if(b){d = extgcd(b, a%b, y, x); y -= (a / b) * x;}
    else{x = 1; y = 0;}
    return d;
}

int main(){
    LL a, b, x, y;
    while(cin >> a >> b){
        int d = extgcd(a, b, x, y);
        cout << x << ' ' << y << ' ' << d << '\n';
    }
} 
