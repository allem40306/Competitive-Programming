/*
source: ABC 141 B Tap Dance
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool ok = true;
    string s;
    cin >> s;
    for(int i = 0; i != (int)s.size(); ++i)
    {
        if(i & 1)
        {
            if(s[i] == 'R')
            {
                ok = false;
            }
        }
        else
        {
            if(s[i] == 'L')
            {
                ok = false;
            }
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}