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

struct Work{
    int t, d;
    bool operator<(const Work &rhs) const { return d < rhs.d; }
};

int main()
{
    IOS;
    int n = 0;
    Work a[10000];
    priority_queue<int> pq;
    while(cin >> a[n].t >> a[n].d)
        ++n;
    sort(a, a + n);
    int sumT = 0, ans = n;
    for (int i = 0; i < n; ++i)
    {
        pq.push(a[i].t);
        sumT += a[i].t;
        if(a[i].d<sumT)
        {
            int x = pq.top();
            pq.pop();
            sumT -= x;
            --ans;
        }   
    }
    cout << ans << '\n';
}
