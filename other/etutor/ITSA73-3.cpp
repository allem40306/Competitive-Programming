#include <bits/stdc++.h>
using namespace std;

void Test(int i, int j)
{
    double x = double(i % 12) * 30.0 + double(j) * 0.5;
    double y = double(j) * 6;
    // cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
    double mn = min(abs(x - y), 360 - abs(x - y));
    if(88.0 <= mn && mn <= 92.0)
    {
        printf("%.2d:%.2d degree=%.2f\n", i, j, mn);
    }
}

int main()
{
    int L, R;
    while(cin >> L >> R)
    {
        for(int i = L; i != R; ++i)
        {
            for(int j = 0; j != 60; ++j)
            {
                Test(i, j);
            }
        }
        Test(R, 0);
    }
}