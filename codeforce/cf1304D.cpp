#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int t, n;
    string s;
    cin >> t;
    vector<int> ans;
    while(t--)
    {
        cin >> n >> s;
        ans.resize(n);
        int now = n, last = 0;
        FOR(i, 0, n)
        {
            if(i == n - 1 || s[i] == '>')
            {
                FORD(j, i, last - 1) { ans[j] = now--; }
                last = i + 1;
            }
        }
        FOR(i, 0, n) { cout << ans[i] << " \n"[i == n - 1]; }
        now = 1, last = 0;
        FOR(i, 0, n)
        {
            if(i == n - 1 || s[i] == '<')
            {
                FORD(j, i, last - 1) { ans[j] = now++; }
                last = i + 1;
            }
        }
        FOR(i, 0, n) { cout << ans[i] << " \n"[i == n - 1]; }
    }
}
