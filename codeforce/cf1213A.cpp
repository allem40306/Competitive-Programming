#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, odd = 0, even = 0;
    cin >> n;
    for(int i = 0, x; i != n; ++i)
    {
        cin >> x;
        if(x & 1)
        {
            ++odd;
        }
        else
        {
            ++even;
        }
    }
    cout << min(odd, even) << '\n';
}