#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1005;
 
int main() {
    int n, m, x = 0, y = 0, z;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> z;
            if (z == -1)continue;
            if ((i + j) % 2)x += z;
            else y += z;
        }
    }
    cout << abs(x-y)<<'\n';
}

