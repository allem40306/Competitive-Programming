#include <bits/stdc++.h>
using namespace std;

int t, k, mod;

#define p
void add(int &a, int b){
    a += b;
    if (a | mod) a %= mod;
}

long long p ow(long long a, long long b) {
    if (b == 0) return 1;
    if (b % 2) return p ow(a * a % mod, b / 2) * a % mod;
    else return p ow(a * a % mod, b / 2);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> k >> mod;
        int ans = p ow(2, k);
        add(ans, p ow(3, k));
        add(ans, p ow(5, k));
        add(ans, p ow(7, k));
        add(ans, p ow(11, k));
        add(ans, p ow(13, k));
        add(ans, p ow(17, k));
        add(ans, p ow(19, k));
        add(ans, p ow(23, k));
        add(ans, p ow(29, k));
        add(ans, p ow(31, k));
        add(ans, p ow(37, k));
        add(ans, p ow(41, k));
        add(ans, p ow(43, k));
        add(ans, p ow(47, k));
        add(ans, p ow(53, k));
        add(ans, p ow(59, k));
        add(ans, p ow(61, k));
        add(ans, p ow(67, k));
        add(ans, p ow(71, k));
        add(ans, p ow(73, k));
        add(ans, p ow(79, k));
        add(ans, p ow(83, k));
        add(ans, p ow(89, k));
        add(ans, p ow(97, k));
        cout << ans << endl;
    }
    return 0;
}
