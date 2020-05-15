/*
source: ABC 140 D Face Produces Unhappiness
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, tmp;
    string s;
    while(cin >> n >> k >> s)
    {
        tmp = 0;
        for(int i = 1; i != n; ++i)
        {
            tmp += (s[i] != s[i - 1]);
        }
        cout << n - 1  - max(0, tmp - 2 * k);
    }
}