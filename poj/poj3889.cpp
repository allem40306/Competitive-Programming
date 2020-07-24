#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

void calc(int n, int id, LL &x, LL &y)
{
    if (n == 1)
    {
        if (id == 1)
        {
            x = 1;
            y = 1;
        }
        else if (id == 2)
        {
            x = 1;
            y = 2;
        }
        else if (id == 3)
        {
            x = 2;
            y = 2;
        }
        else if (id == 4)
        {
            x = 2;
            y = 1;
        }
        // cout << n << ' ' << x << ' ' << y << '\n';
        return;
    }
    LL _id = (1 << (n - 1)) * (1 << (n - 1));
    if (id <= _id)
    {
        calc(n - 1, id, y, x); // rotate
    }
    else if (id <= 2 * _id)
    {
        calc(n - 1, id - _id, x, y);
        y += (1 << (n - 1)); // y -> 2^(n-1) + y
    }
    else if (id <= 3 * _id)
    {
        calc(n - 1, id - 2 * _id, x, y);
        x += (1 << (n - 1)); // x -> 2^(n-1) + x
        y += (1 << (n - 1)); // y -> 2^(n-1) + y
    }
    else if (id <= 4 * _id)
    {
        calc(n - 1, id - 3 * _id, y, x); // rotate
        x = (1 << n) + 1 - x;            // x -> 2^n+1-x
        y = (1 << (n - 1)) + 1 - y;      // x -> 2^(n-1)+1-y
    }
    // cout << n << ' ' << x << ' ' << y << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LL n, a, b;
        LL x1, x2, y1, y2;
        cin >> n >> a >> b;
        calc(n, a, x1, y1);
        calc(n, b, x2, y2);
        x1 -= x2;
        y1 -= y2;
        cout << fixed << setprecision(0) << sqrt((double)(x1 * x1 + y1 * y1)) * 10
             << '\n';
    }
}