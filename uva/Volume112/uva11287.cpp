#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

bool isPrime(LL n)
{
    for (LL i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

LL fPow(LL a, LL b, LL c)
{
    LL ret = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1)
            ret = (ret * a) % c;
        a = (a * a) % c;
    }
    return ret;
}

int main()
{
    IOS;
    LL p, a;
    while (cin >> p >> a, p || a)
    {
        // cout << fPow(a, p, p) << '\n';
        if (!isPrime(p) && fPow(a, p, p) == a % p)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
