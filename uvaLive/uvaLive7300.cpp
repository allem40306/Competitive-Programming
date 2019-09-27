#include <bits/stdc++.h>
using namespace std;

int T(char ch)
{
    int tmp = (isalpha(ch) ? (ch - 'A' + 10) : (ch - '0'));
    return tmp;
}

int main()
{
    string s;
    while(cin >> s)
    {
        for(int i = 0; i < (int)s.size(); i += 2)
        {
            int tmp = 16 * T(s[i]) + T(s[i + 1]);
            cout << char(tmp);
        }
        cout << '\n';
    }
}