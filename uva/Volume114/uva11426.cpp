#include <bits/stdc++.h>
using namespace std;
const int N = 4000005;
typedef long long LL;
LL phi[N], a[N] = {};

void phi_table(int n){
    phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(phi[i])continue;
        for(int j = i; j < n; j += i){
            if(!phi[j])phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
    }
}

void sol(int n){
    for(int i = 2; i < n; i++){
        for(int j = 1; i * j < n; j++){
            a[i * j] += j * phi[i];
        }
    }
    for(int i = 1; i < n; i++){
        a[i] += a[i - 1];
    }
}

int main(){
    phi_table(N);
    sol(N);
    int n;
    while(cin >> n, n){
        cout << a[n] << '\n';
    }
}