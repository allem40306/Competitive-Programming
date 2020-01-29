/*
source: ABC 152 E Flatten
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const LL MOD = 1e9 + 7;
const int N = 1000005;
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
bitset<N> is_notp;
vector<int> p;
map<int, int> cnt;

void primeTable()
{
    is_notp.reset();
    is_notp[0] = is_notp[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!is_notp[i])
        {
            p.push_back(i);
        }
        for (int j = 0; j < (int)p.size() && i * p[j] < N; j++)
        {
            is_notp[i * p[j]] = 1;
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
}

void Update(int idx, int val)
{
    if(cnt.find(idx) == cnt.end())
    {
        cnt[idx] = val;
    }
    else
    {
        cnt[idx] = max(cnt[idx], val);
    }
    return;
}

void Factorization(LL x)
{
    for (int i = 0, tmp; i < (int)p.size() && p[i] * p[i] <= x; ++i)
    {
        tmp = 0;
        while(x % p[i] == 0)
        {
            x /= p[i];
            ++tmp;
        }
        Update(p[i], tmp);
    }
    if(x != 1)
    {
        Update((int)x, 1);
    }
    return;
}

LL calcLCM() {
    LL ret = 1;
    for (auto it: cnt)
    {
        while(it.second--)
        {
            ret = (ret * it.first) % MOD;
        }
    }
    return ret;
}

LL pow2(LL a, LL b)
{ 
    LL ret = 1;
    for (;b; b >>= 1)
    {
        if((b & 1) != 0)
        {
            ret = (ret * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ret;
}

int main()
{
    IOS;
    int n;
    vector<LL> v;
    primeTable();
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        Factorization(v[i]);
    }
    LL ans = 0, LCM = calcLCM();
    for (int i = 0; i < n; ++i)
    {
        LL tmp = (LCM * pow2(v[i], MOD - 2)) % MOD;
        // cout << tmp << " \n"[i == n - 1];
        ans = (ans + tmp) % MOD;
    }
    cout << ans << '\n';

}
