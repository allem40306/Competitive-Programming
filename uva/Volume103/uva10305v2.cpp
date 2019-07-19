#include <bits/stdc++.h>
using namespace std;
const int MXV = 105;

int main(){
    int m, n;
    int din[MXV];
    vector<int> G[MXV];
    queue<int> q;
    vector<int> v;
    while(cin >> m >> n, m || n){
        memset(din, 0, sizeof(din));
        v.clear();
        for(int i = 1; i <= m; ++i){
            G[i].clear();
        }
        for(int i = 0, x, y; i != n; ++i){
            cin >> x >> y;
            G[x].push_back(y);
            ++din[y];
        }
        for(int i = 1; i <= m; ++i){
            if(din[i] == 0){
                q.push(i);
            }
        }
        for(int i = 0; i != m; ++i){
            auto k = q.front(); q.pop();
            v.push_back(k);
            for(auto it: G[k]){
                if(--din[it] == 0){
                    q.push(it);
                }
            }
        }
        for(int i = 0; i != m; ++i){
            if(i)cout << ' ';
            cout << v[i];
        }
        cout << '\n';
    }
}