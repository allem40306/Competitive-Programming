#include <iostream>
using namespace std;
const int Mod = 2076030;
 
int main() {
    long long n, m = 2, ans = 1;
    cin >> n;
    while (n) {
        if (n & 1) {
            ans = (ans * m) % Mod;
        }
        m = (m * m) % Mod;
        n >>= 1;
    }
    cout << ans << '\n';
}