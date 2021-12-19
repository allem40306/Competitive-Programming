#include <bits/stdc++.h>
using namespace std;
const int N = 25;

int main()
{
    int t;
    string s;
    cin >> t >> ws;
    while (t--)
    {
        getline(cin, s);
        stringstream ss(s);
        int x;
        vector<int> a;
        while (ss >> x)
        {
            a.emplace_back(x);
        }
        bitset<10000> dp(0);
        dp[0] = true;
        int sum = 0;
        for (auto x : a)
        {
            sum += x;
            for (int i = sum; i - x >= 0; --i)
            {
                // cout << i << ' ' << dp[i] << ' '
                //      << i - x << ' ' << dp[i - x] << '\n';
                if (dp[i - x] == true)
                {
                    dp[i] = true;
                }
            }
        }
        if (sum % 2 || dp[sum / 2] == false)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}