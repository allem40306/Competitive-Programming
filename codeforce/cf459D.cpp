#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x))
int n;
vector<long long> BIT;

void update(int x)
{
    for(; x <= n; x += lowbit(x))
    {
        ++BIT[x];
    }
}

long long  query(int x)
{
    long long  ans = 0;
    for(; x > 0; x -= lowbit(x))
    {
        ans += BIT[x];
    }
    return ans;
}

int main()
{
    vector<long long> v, v1, cnt, F; //f(i) = f(1,i,a_i) 
    cin >> n;
    v.resize(n);
    cnt.resize(n);
    F.resize(n);
    for(int i = 0; i != n; ++i)
    {
        cin >> v[i];
        v1.push_back(v[i]);
    }
    sort(v1.begin(), v1.end());
    v1.resize(unique(v1.begin(), v1.end()) - v1.begin());
    for(int i = 0, no; i != n; ++i)
    {
        no = lower_bound(v1.begin(), v1.end(), v[i]) - v1.begin();
        ++cnt[no];
        F[i] = cnt[no];
    }

    long long ans = 0;
    BIT.resize(2 * n, 0);
    for(int i = n - 1, no; i >= 0; --i)
    {
        no = lower_bound(v1.begin(), v1.end(), v[i]) - v1.begin();
        int q = cnt[no] - F[i] + 1;
        // cout << no << ' ' << F[i] << ' ' << q << '\n';
        ans += query(F[i] - 1);
        // cout << ans << '\n';
        update(q);
    }
    cout << ans << '\n';
}