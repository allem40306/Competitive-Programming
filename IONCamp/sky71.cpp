#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> cnt(1005);
    for(int i = 0, x; i != n; ++i)
    {
        cin >> x;
        ++cnt[x];
    }
    for(int i = 0, j = 1000; i != k; ++i)
    {
        while(j > 0 && cnt[j] == 0)--j;
        sum += j;
        --cnt[j];
    }
    cout << sum << '\n';
}
