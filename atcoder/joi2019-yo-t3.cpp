#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;

int main(){
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; )
    {
        if(i != n - 1 && s[i] != s[i + 1])
        {
            i += 2;
            ++ans;
        }
        else
        {
            i += 1;
        }
    }
    cout << ans << '\n';
}