#include <iostream>
using namespace std;
 
int main() {
    long long int n, k, x1, x2, tmp;
    cin >> n >> k >> x1 >> x2;
    for (int i = 0; i < n; i++) {
        if (i)cout << ' ';
        if(n-i-1>k){
            cout<<1;
            continue;
        }
        tmp = min(k, n - i - 1);
        cout << 1 + tmp;
        k -= tmp;
    }
    cout << '\n';
}