/*
source: ABC 117 C Streamline
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    vector<int> v, dis;
    cin >> n >> m;
    v.resize(m);
    for(int i = 0; i != m; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 1; i != m; ++i)
    {
        dis.push_back(v[i] - v[i - 1]);
    }
    sort(dis.begin(), dis.end());
    int ans = 0;
    for(int i = 0; i < (int)dis.size() - n + 1; ++i)
    {
        ans += dis[i];
    }
    cout << ans << '\n';
}