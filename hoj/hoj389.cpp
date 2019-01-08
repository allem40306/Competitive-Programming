#include <iostream>
using namespace std;
const int N = 105;
const long long Mod = 10000000000;
 
int main() {
    int n;
    long long ans = 1;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        ans *= i;
        while (!(ans % 10))ans /= 10;
        ans %= Mod;
    }
    cout << ans % 10 << '\n';
}