#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x, y, n, m;
    cin >> t;
    while (t--)
    {
        /*
        1 1 m
        x y n
        */
        cin >> n >> x >> y >> m;
        int dx = m * y - n;
        int dy = n - x * m;
        int d = y - x;
        cout << (dx / d) << ' ' << (dy / d) << '\n';
    }
    
}