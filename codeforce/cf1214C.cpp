#include <bits/stdc++.h>
using namespace std;

bool ok(string s)
{
    int tmp = 0, miss = 0, a = 0;
    for(int i = 0; i != (int)s.size(); ++i)
    {
        if(s[i] == '(')
        {
            ++a;
        }
        else
        {
            --a;
        }
        if()
    }
    return true;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;
    if(n % 2 == 0 && ok(s))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}