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

map<int, vector<pair<int, int>>> tb;
vector<int> v;

void sol()
{
    for (int i = (int)v.size() - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            int diff = v[i] - v[j];
            if (tb.find(diff) == tb.end())
                continue;
            for (auto &item : tb[diff])
            {
                if (item.first != i && item.first != j &&
                    item.second != i && item.second != j)
                {
                    cout << v[i] << '\n';
                    return;
                }
            }
        }
    }
    cout << "no solution\n";
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        v.clear();
        tb.clear();
        for (int i = 0, x; i < n; ++i)
        {
            cin >> x;
            v.emplace_back(x);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < (int)v.size(); ++i)
        {
            for (int j = i + 1; j < (int)v.size(); ++j)
            {
                int sum = v[i] + v[j];
                if (tb.find(sum) == tb.end())
                {
                    tb.insert({sum, vector<pair<int, int>>()});
                }
                tb[sum].push_back(make_pair(i, j));
            }
        }
        sol();
    }
}