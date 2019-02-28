#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n;
int phi[N], a[N];

void phi_table(int n){
    phi[0] = 0; phi[1] = 1;
    for(int i = 2;i < n; i++){
        if(phi[i])continue;
        for(int j = i; j < n; j += i){
            if(!phi[j])phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}

int sti(string s){
    int ret = 0;
    for(int i = 0;i < s.size(); i++){
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

int POW(int a, int b, int mod){
    int ret = 1;
    int tmp = 1;
    for(int i = 0; i < b; i++){
        tmp *= a;
        if(tmp > mod)break;
    }
    tmp = (tmp >= mod) ? mod : 0;
    for(; b; b >>= 1){
        if(b & 1)ret = ret * a % mod;
        a = a * a % mod;
    }
    return ret + tmp;
}

int dfs(int d, int MOD){
    if(d == n - 1){
        if(a[d] >= MOD)return (a[d] % MOD) + MOD;
        return a[d];
    }
    int k = dfs(d + 1, phi[MOD]);
    return POW(a[d], k, MOD);
}

int main(){
    phi_table(N);
    int m, ti = 1;
    string s;
    while(cin >> s, s != "#"){
        m = sti(s);
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout<< "Case #" << ti++ << ": " << dfs(0, m) % m << '\n' ;
    }
}