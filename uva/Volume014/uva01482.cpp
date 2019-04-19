#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL SG(LL x){return ((x&1)?(SG(x>>1)):(x>>1));}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        LL x, ans = 0;
        while(n--){
            cin >> x;
            ans ^= SG(x);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
} 
