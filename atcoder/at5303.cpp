/*
source: ABC 152 B Comparing Strings
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int a, b;
    cin >> a >> b;
    if(a > b)
    {
        swap(a, b);
    }
    while(b--)
    {
        cout << a;
    }
    cout << '\n';
}