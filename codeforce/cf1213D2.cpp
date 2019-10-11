#include <bits/stdc++.h>
using namespace std;
const int MXN = 200005;
vector<int> v, times[MXN];

int main(){
    int n, k;
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i != MXN; ++i)
    {
        times[i].clear();
    }
    for(int i = 0; i != n; ++i)
    {
        cin >> v[i];
        int tmp = v[i], cnt = 0;
        while(1)
        {
            times[tmp].push_back(cnt);
            if(!tmp)
            {
                break;
            }
            tmp /= 2;
            ++cnt;
        }
    }
    int ans = 500000000;
    for(int i = 0; i != MXN; ++i)
    {
        if((int)times[i].size() < k)
        {
            continue;
        }
        sort(times[i].begin(), times[i].end());
        ans = min(ans, accumulate(times[i].begin(), times[i].begin() + k, 0));
    }
    cout << ans << '\n';
}