#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MXV = 3e5 + 5;
const LL MOD = 10009;
const LL seed = 31;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);

int main()
{
    int t = 0;
    cin >> t;
    FOR(ti, 1, t + 1)
    {
        LL i, j;
        cin >> i >> j;
        int ansL = 0, ansR = 0;
        while (i != 1 || j != 1)
        {
            // cout << i << ' ' << j << '\n';
            if (i == 1 || j == 1)
            {
                ansL += i - 1;
                ansR += j - 1;
                break;
            }
            if (i < j)
            {
                ansR += (j - j % i) / i;
                j %= i;
            }
            else
            {
                ansL += (i - i % j) / j;
                i %= j;
            }
            // cout << ansL << ' ' << ansR << "\n";
        }
        cout << "Scenario #" << ti << ":\n";
        cout << ansL << ' ' << ansR << "\n\n";
    }
}