#include <bits/stdc++.h>
using namespace std;
const int MXV = 105;

int main(){
    int t, m, n;
    int din[MXV];
    bool d = false;
    vector<int> G[MXV];
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v;
    cin >> t;
    while(t--){
        cin >> m >> n;
        memset(din, 0, sizeof(din));
        v.clear();
        for(int i = 1; i <= m; ++i){
            G[i].clear();
        }
        for(int i = 0, x, y, z; i != n; ++i){
            cin >> x >> y;
            while(y--){
                cin >> z;
                G[z].push_back(x);
                ++din[x];
            }
        }
        for(int i = 1; i <= m; ++i){
            if(din[i] == 0){
                pq.push(i);
            }
        }
        for(int i = 0; i != m; ++i){
            auto k = pq.top(); pq.pop();
            v.push_back(k);
            for(auto it: G[k]){
                if(--din[it] == 0){
                    pq.push(it);
                }
            }
        }
        if(d){
            cout << '\n';
        }
        d = true;
        for(int i = 0; i != m; ++i){
            if(i)cout << ' ';
            cout << v[i];
        }
        cout << '\n';
    }
}