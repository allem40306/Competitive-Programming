#include <bits/stdc++.h>
using namespace std;
const int N = 1000015;
bitset<3 * N> is_notp;

void Prime_table(long long n){
    is_notp.reset();
    is_notp[0] = is_notp[1] = 1;
    for(long long i = 2; i < n; i++){
        if(is_notp[i])continue;
        for(long long j = i * i; j < n; j += i){
            is_notp[j] = 1;
        }
    }
}

int main(){
    Prime_table(3 * N);
    static int a[N]; a[0] = 0;
    for(int i = 1; i < N; i++){
        a[i] = a[i - 1] + (is_notp[3 * i + 7] ? 0 : 1);
    }
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout<< a[n] <<'\n';
    }
}