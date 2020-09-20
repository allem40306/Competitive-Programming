#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;

int main(){
    int n, m;
    cin >> n;
    vector<int> v(n+5);
    set<int> s;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        s.insert(v[i]);
    }
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        int x;
        cin >> x;
        int cur = v[x];
        if(cur == 2019 || s.count(cur + 1))
        {
            continue;
        }
        s.erase(cur);
        s.insert(cur + 1);
        v[x] = cur + 1;
    }
    for(int i = 1; i <= n; ++i)
    {
        cout << v[i] << "\n";
    }
}