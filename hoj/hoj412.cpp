#include <iostream>
#include <cmath>
using namespace std;
#define ULL unsigned long long
 
int main() {
    int t;
    ULL x, y, tmp;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        tmp = max(x, y);
        if (tmp % 2 == 0)swap(x, y);
        if (x > y)cout << (tmp - 1)*(tmp - 1) + y << '\n';
        else cout << tmp*tmp - x + 1 << '\n';
    }
}