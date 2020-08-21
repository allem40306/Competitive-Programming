#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;
struct Data
{
    int s, t, n, cost;
    bool operator<(const Data &rhs) const { return cost < rhs.cost; }
};
int n, b, t;
int ans;
vector<int> costSum(25), sum(10);
vector<Data> v;

void doit(int d, int dir)
{
    sum[v[d].s] += dir * v[d].n;
    sum[v[d].t] -= dir * v[d].n;
}

bool ok()
{
    int total = 0;
    for (int i = 0; i <= b; ++i)
    {
        total += sum[i];
        if (total > n)
        {
            return false;
        }
    }
    return true;
}

void dfs(int d, int cur)
{
    // cout << d << ' ' << cur << '\n';
    ans = max(ans, cur);
    if (d == t)
    {
        return;
    }
    if(cur + costSum[d] <= ans)
    {
        return;
    }
    doit(d, 1);
    if (ok())
    {
        dfs(d + 1, cur + (v[d].t - v[d].s) * v[d].n);
    }
    doit(d, -1);
    dfs(d + 1, cur);
    return;
}

int main()
{
    while (cin >> n >> b >> t, n || b || t)
    {
        v.resize(t);
        fill(sum.begin(), sum.end(), 0);
        fill(costSum.begin(), costSum.end(), 0);
        for (int i = 0; i < t; ++i)
        {
            cin >> v[i].s >> v[i].t >> v[i].n;
            v[i].cost = v[i].n * (v[i].t - v[i].s);
        }
        sort(v.begin(), v.end());
        for (int i = t - 1; i >= 0; --i)
        {
            costSum[i] = costSum[i + 1] + v[i].cost;
        }
        ans = 0;
        dfs(0, 0);
        cout << ans << '\n';
    }
}