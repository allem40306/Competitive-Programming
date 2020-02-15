#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const LL INF = 1e18;
const int MXN = 0;
const int MXV = 0;
#define MP  make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n, cnt = 0;
    LL x;
    vector<LL> even;
    cin >> n;
    FOR(i, 0, n)
    {
        cin >> x;
        if((x & 1) == 0)
        {
            even.push_back(x);
        }
    }
    sort(even.begin(), even.end());
    cnt = even.size();
    if(cnt <= 1)
    {
        cout << "NO\n";
    }
    else if((cnt & 1) == 1)
    {
        cout << "OuO\n";
        cout << even[0] << "\n";
    }
    else
    {
        cout << "YES\n";
        FOR(i, 0, cnt) { cout << even[i] << " \n"[i == cnt - 1]; }
    }
}
