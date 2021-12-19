#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MXV = 3e5 + 5;
const ULL MOD = 10009;
const ULL seed = 31;
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
    int n, m, ti = 0;
    vector<int> order;
    string s, r;
    while (cin >> n, n)
    {
        order.resize(n);
        char ch;
        FOR(i, 0, n) { cin >> ch >> order[i]; }
        cin >> s;
        cout << "S-Tree #" << ++ti << ":\n";
        cin >> m;
        FOR(i, 0, m)
        {
            cin >> r;
            int x = 0;
            FOR(j, 0, n)
            {
                if (r[order[j] - 1] == '0')
                {
                    x = 2 * x;
                }
                else
                {
                    x = 2 * x + 1;
                }
            }
            cout << s[x];
        }
        cout << "\n\n";
    }
}