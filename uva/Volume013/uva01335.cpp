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
int n;
vector<int> r, Left, Right;

bool ok(int x)
{
    // cout << "test: " << x << '\n';
    int L, R;
    L = Left[1] = r[1];
    R = x - L;
    Right[1] = 0;
    FOR(i, 2, n + 1)
    {
        if(i % 2 == 1)
        {
            Right[i] = min(R - Right[i - 1], r[i]);
            Left[i] = r[i] - Right[i];
        }
        else
        {
            Left[i] = min(L - Left[i - 1], r[i]);
            Right[i] = r[i] - Left[i];
        }
        // cout << i << ' ' << Left[i] << ' ' << Right[i] << '\n';
    }
    return Left[n] == 0;
}

int main()
{
    // IOS;
    while(cin >> n, n)
    {
        r.resize(n + 5);
        Left.resize(n + 5);
        Right.resize(n + 5);
        FOR(i, 1, n + 1) { cin >> r[i]; }
        if(n == 1)
        {
            cout << r[1] << '\n';
            continue;
        }
        int L = 0, R = 0;
        r[n + 1] = r[1];
        FOR(i, 1, n + 1) { L = max(L, r[i] + r[i + 1]); }
        if(n % 2)
        {
            FOR(i, 1, n + 1) { R = max(R, r[i] * 3); }
            while(L != R)
            {
                // cout << L << ' ' << R << '\n';
                int M = L + ((R - L) >> 1);
                if(ok(M))
                {
                    R = M;
                }
                else
                {
                    L = M + 1;
                }
            }
        }
        cout << L << '\n';
    }
}
