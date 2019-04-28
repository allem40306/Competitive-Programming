#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
const int LOG = 20;
vector<int>G[N];
int tin[N], tout[N], tot;
int p[N][LOG], w[N], extra[N], dep[N];

void dfs(int s, int f, int d){
    tin[s] = ++tot;
    dep[s] = d;
    for(auto it: G[s]){
        if(it == f)continue;
        p[it][0] = s;
        dfs(it, s, d + 1);
    }
    tout[s] = ++tot;
}

void build(int n){
    for(int i = 1; i < LOG; ++i){
        for(int j = 1; j <= n; ++j){
            if(p[j][i - 1] != -1)p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }
}

bool anc(int x, int y){
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y){
    if(dep[x] > dep[y])swap(x, y);
    if(anc(x, y))return x;
    for(int i = LOG - 1; i >= 0; --i){
        if(p[x][i] != -1 && !anc(p[x][i], y))x = p[x][i];
    }
    return p[x][0];
}

void init(int n){
    for(int i = 0; i < n; ++i)G[i].clear();
    for(int i = 1, x, y; i < n; ++i){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    memset(w, 0, sizeof(w));
    memset(extra, 0, sizeof(extra));
    memset(p, -1, sizeof(p));
    tot = 0;
    dfs(0, -1, 0);
    build(n);
}

void dfs2(int s, int f, int w[]){
    for(auto it: G[s]){
        if(it == f)continue;
        dfs2(it, s, w);
        w[s] += w[it];
    }
}

int main(){
    int t, n, q;
    cin >> t;
    for(int ti = 1; ti <= t; ++ti){
        cin >> n;
        init(n);
        cin >> q;
        for(int i = 0, x, y, z, ww; i < q; ++i){
            cin >> x >> y >> ww;
            z = lca(x, y);
            extra[z] += ww;
            w[x] += ww;
            w[y] += ww;
            w[z] -= 2 * ww;
        }
        dfs2(0, -1, w);
        cout << "Case #" << ti << ":\n";
        for(int i = 0; i < n; ++i){
            cout << w[i] + extra[i] << '\n';
        }
    }

}