#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 250000;
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
vector<int> p;
vector<double> fib(MXN);
bitset<MXN> is_notp;

void primeTable()
{
    is_notp.reset();
    is_notp[0] = is_notp[1] = 1;
    p.push_back(1);
    for (int i = 2; i < MXN; i++)
    {
        if (!is_notp[i])
        {
            p.push_back(i);
        }
        for (int j = 1; j < (int)p.size() && i * p[j] < MXN; j++)
        {
            is_notp[i * p[j]] = 1;
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
}

void fibTable()
{
    fill(fib.begin(), fib.end(), 0);
    fib[0] = 0;
    fib[1] = 1;
    bool div = false;
    FOR(i, 2, fib.size())
    {
        if (div)
        {
            fib[i] = fib[i - 1] + fib[i - 2] / 10;
            div = false;
        }
        else
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        if (fib[i] >= 1e9)
        {
            fib[i] /= 10;
            div = true;
        }
        // if(i <= 60)cout << i << ' ' << div << ' ' << fib[i] << '\n';
    }
    fib[2] = 2;
    fib[3] = 3;
}

int main()
{
    IOS;
    primeTable();
    fibTable();
    int n;
    while (cin >> n)
    {
        // cout << p[n] << '\n';
        cout << (int)fib[p[n]] << '\n';
    }
}
