/*
source: AtCoder Beginner Contest 155 C
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n, mx = 0;
    cin >> n;
    map<string, int> tb;
    string s;
    FOR(i, 0, n)
    {
        cin >> s;
        if(tb.find(s) == tb.end())
        {
            tb[s] = 0;
        }
        tb[s] += 1;
        if(mx < tb[s])
        {
            mx = tb[s];
        }
    }
    for(auto it: tb)
    {
        if(it.S == mx)
        {
            cout << it.F << '\n';
        }
    }
}
