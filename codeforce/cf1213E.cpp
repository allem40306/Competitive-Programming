#include <bits/stdc++.h>
using namespace std;

void sol(int n, string s, string t)
{
    string tmp = "abc", res;
    do
    {
        res = string(n, tmp[0]) + string(n, tmp[1]) + string(n, tmp[2]);
        if(res.find(s) == string::npos && res.find(t) == string::npos)
        {
            cout << "YES\n" << res << '\n';
            return;
        }
        res = "";
        for(int i = 0; i != n; ++i)
        {
            res += tmp;
        }
        if(res.find(s) == string::npos && res.find(t) == string::npos)
        {
            cout << "YES\n" << res << '\n';
            return;
        }
    }while(next_permutation(tmp.begin(), tmp.end()));
    cout << "NO\n";
    return;
}

int main()
{
    int n;
    string s, t, ans1, ans2;
    cin >> n >> s >> t;
    sol(n, s, t);    
}