#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
 
int main() {
    long long t, n, a[N];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] - a[0];
        }
        cout << ans << '\n';
    }
}