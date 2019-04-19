#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    while(cin >> n >> m, n || m){
        if(n > m)swap(n, m);
        cout << (m + n - 2) * n * m + 2 * n * (n - 1) * (3 * m - n - 1) / 3 << '\n';
    }
} 
