#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9+7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    LL a, b, c;
    while(cin >> a >> b >> c)
    {
        LL ans = 1;
        for (;b;b>>=1)
        {
            if(b&1)
                ans = ans * a % c;
            a = a * a % c;
        }
        cout << ans % c << '\n';
    }
}