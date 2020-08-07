#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
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

double A, L;
double x, y;
double ansx = 1, ansy = 1;

void update()
{
    if (abs(x / y - A) < abs(ansx / ansy - A))
    {
        ansx = x;
        ansy = y;
    }
}

int main()
{
    IOS;
    cin >> A >> L;
    x = y = 1;
    update();
    while (x < L && y < L)
    {
        // cout << x << ' ' << y << '\n';
        if (x / y > A)
        {
            y += 1.0;
        }
        else
        {
            x += 1.0;
        }
        update();
    }
    cout << fixed << setprecision(0) << ansx << ' ' << ansy << '\n';
}