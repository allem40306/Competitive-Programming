#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 10000005;
const LL MOD = 100000007; 
LL facs[N], phi[N];
bitset<N> is_prime;

LL extgcd(LL a, LL b, LL &x, LL &y){
    if(!b){x = 1; y = 0; return a;}
    LL d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

LL inv(LL a, LL n){
    LL x, y;
    extgcd(a, n, x, y);
    return (x + n) % n;
}

void build(){
    facs[0] = facs[1] = 1;
    phi[0] = phi[1] = 1;
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(LL i = 2; i < N; i++){
        facs[i] = (facs[i - 1] * i) % MOD;
        phi[i] = phi[i - 1];
        if(!is_prime[i])continue;
        phi[i] = phi[i] * (i - 1) % MOD * inv(i, MOD) % MOD;
        for(LL j = i * i; j < N; j += i){
            is_prime[j] = 0;
        }
    }
}


int main(){
    build();
    int n, m;
    while(cin >> n >> m, n || m){
        cout << (facs[n] * phi[m] - 1 + MOD) % MOD << '\n';
    }
}