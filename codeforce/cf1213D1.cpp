#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    vector<int> v, w;
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i != n; ++i)
    {
        cin >> v[i];
        int tmp = v[i];
        while(1)
        {
            w.push_back(tmp);
            if(!tmp)
            {
                break;
            }
            tmp /= 2;
        }
    }
    sort(w.begin(), w.end());
    w.resize(unique(w.begin(), w.end()) - w.begin());
    int ans = 500000;
    vector<int> times;
    for(int i = 0; i != (int)w.size(); ++i)
    {
        times.clear();
        for(int j = 0; j != n; ++j)
        {
            int cnt = 0, tmp = v[j];
            while(tmp > w[i])
            {
                tmp /= 2;
                ++cnt;
            }
            if(tmp == w[i])
            {
                times.push_back(cnt);
            }
        }
        if((int)times.size() < k)
        {
            continue;
        }
        sort(times.begin(), times.end());
        ans = min(ans, accumulate(times.begin(), times.begin() + k, 0));
    }
    cout << ans << '\n';
}