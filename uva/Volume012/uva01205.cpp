#include <bits/stdc++.h>
using namespace std;
const int MXN = 1005;

struct Data{
    int n;
    double w;
}a[MXN];

int main(){
    int n, root;
    int w[MXN], f[MXN];
    bitset<MXN>vis;
    while(cin >> n >> root, n || root){
        int ans = 0;
        priority_queue <pair<double, int>> pq;
        for(int i = 1; i <= n; ++i){
            cin >> w[i];
            ans += w[i];
            a[i] = {1, w[i] * 1.0};
            if(i == root)continue;
            pq.push({a[i].w, i});
        }
        for(int i = 1, x, y; i != n; ++i){
            cin >> x >> y;
            f[y] = x;
        }
        vis.reset();
        for(int i = 1, x, p; i != n; ++i){
            do{
                x = pq.top().second;
                pq.pop();
            }while(vis[x] || x == root);
            vis[x] = true;
            p = f[x];
            for(int j = 1; j <= n; ++j){
                if(f[j] == x)
                    f[j] = p;
            }
            ans += a[p].n * w[x];
            w[p] += w[x];
            a[p].n += a[x].n;
            a[p].w = double(w[p]) / double(a[p].n);
            pq.push({a[p].w, p});
        }
        cout << ans << '\n';
    }
}