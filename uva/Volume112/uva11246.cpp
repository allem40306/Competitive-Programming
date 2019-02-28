#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int sol(LL n, LL k){
    LL ret = 0;
    LL sign = 1;
    while(n){
        ret += n * sign;
        n /= k;
        sign *= -1;
    }
    return ret;
}

int main(){
    LL t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << sol(n, k) << '\n';
    }
}