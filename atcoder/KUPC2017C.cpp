/*
source: KUPC 2017 C Best Password 
*/
#include <bits/stdc++.h>
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
using namespace std;
const int MXN = 1005;
int a[MXN];

void show(int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    cout << '\n';
}

int main()
{
    IOS;
    int A, n;
    string s;
    memset(a, 0, sizeof(a));
    cin >> A >> s;
    n = (int)s.size();
    for(int i = 0; i < n; ++i)
    {
        a[i] = int(s[i] - 'a') + 1;
    }
    // show(n);
    for(int i = 0; i <= n + 5; ++i)
    {
        for(int j = n - 1; j > 0; --j)
        {
            int dif = 26 - a[j - 1];
            int give = min(dif / A, a[j]);
            // cout << dif << ' '  << give << '\n';
            a[j] -= give;
            a[j - 1] += give * A;
        }
        // show(n);
    }
    int tail = n - 1;
    while(a[tail] == 0)
    {
        --tail;
    }
    for(int i = 0; i <= tail; ++i)
    {
        cout << char('a' + (a[i] - 1));
    }
    cout << '\n';
}