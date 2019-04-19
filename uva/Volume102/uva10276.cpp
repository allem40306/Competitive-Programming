#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int main(){
    long long a[N] = {0, 1, 3};
    for(int i = 2; i <= 50; i += 2){
        a[i + 1] = a[i] + i + 2;
        a[i + 2] = a[i + 1] + i + 2;
    }
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << a[n] << '\n';
    }
}