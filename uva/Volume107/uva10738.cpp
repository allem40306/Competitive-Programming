#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 1000005;
const int MXV = 0;
#define MP  make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
bitset<MXN> is_notp;
vector<int> p;

void primeTable()
{
    is_notp.reset();
    is_notp[0] = is_notp[1] = 1;
    for (int i = 2; i * i < MXN; ++i)
    {
        if (!is_notp[i])
        {
            p.push_back(i);
        }
        for (int j = 0; j < (int)p.size() && i * p[j] < MXN; j++)
        {
            is_notp[i * p[j]] = 1;
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
}

vector<int> a(MXN, 0), sum(MXN, 0);

void primeFactor(int x)
{
    int y = x, primeFactor = 0;
    bool squareFree = true;
    for(auto i: p)
    {
        if(y < i)
        {
            break;
        }
        if(y % i != 0)
        {
            continue;
        }
        ++primeFactor;
        y /= i;
        while(y % i == 0)
        {
            squareFree = false;
            y /= i;
        }
    }
    if(y != 1)
    {
        ++primeFactor;
    }
    if(squareFree == false)
    {
        a[x] = 0;
    }
    else
    {
        a[x] = ((primeFactor & 1) ? -1 : 1);
    }
    sum[x] = sum[x - 1] + a[x];
    return;
}

int main()
{
    IOS;
    primeTable();
    FOR(i, 1, MXN) { primeFactor(i); }
    int n;
    while(cin >> n, n)
    {
        cout << setw(8) << n << setw(8) <<  a[n] << setw(8) <<  sum[n] << '\n';
    }
}
