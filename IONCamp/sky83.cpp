#include <bits/stdc++.h>
using namespace std;

string sumToRstring(long long sum)
{
    // cout << "de:" << sum << '\n';
    if(sum == 0)
    {
        return "0";
    }
    string s = "";
    while(sum)
    {
        s += char((sum % 10) + '0');
        sum /= 10;
    }
    return s;
}

// long long sumToRint(long long sum)
// {
//     long long x = 0;
//     // cout << "de:" << sum << '\n';
//     while(sum)
//     {
//         x = x * 10 + (sum % 10);
//         sum /= 10;
//     }
//     return x;
// }

int main()
{
    long long x, sum = 0;
    int order;
    string s, t, r, rsum;
    cin >> s >> t >> ws;
    getline(cin, r);
    stringstream ss(r);
    while(ss >> x)
    {
        sum += x;
    }
    rsum = sumToRstring(sum);
    cin >> order;
    if(order == 1)
    {
        cout << rsum;
    }
    cout << s;
    if(order == 2)
    {
        cout << rsum;
    }
    cout << t;
    if(order == 3)
    {
        cout << rsum;
    }
    cout << '\n';
}