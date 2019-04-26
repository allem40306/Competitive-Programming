#include <bits/stdc++.h>
using namespace std;
const int N = 30005;
vector<int>G[N];
int p[N][20], dep[N], tin[N], tout[N], tot;

void dfs(int s, int f){
    tin[s] = ++tot;
    p[s][0] = f;
    dep[s] = dep[f] + 1;
    for(auto it: G[s]){
        dfs(it, s);
    }
    tout[s] = ++tot;
    // cout << s << ' ' << tin[s] << ' ' << tout[s] << '\n';
}

void build(int n){
    for(int i = 1; i < 20; ++i){
        for(int j = 1; j <= n; ++j){
            if (p[j][i - 1] == -1)continue;
			p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }
}

void init(int n){
    for(int i = 0; i <= n; ++i)G[i].clear();
    for(int i = 1, x; i <= n; ++i){
        while(cin >> x, x){
            G[i].push_back(x);
        }
    }
    tot = 0;
    dep[1] = 0;
    memset(p, -1, sizeof(p));
    dfs(1, -1);
    build(n);
}

bool anc(int x, int y){
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

void sol(int x, int y){
    int tmp = dep[x] + dep[y];
    if(dep[x] < dep[y])swap(x, y);
    if(anc(x, y)){
        cout << x << ' ' << tmp - 2 * dep[x] << '\n';
        return;
    }
    for(int i = 20 - 1; i >= 0; --i){
        // cout << "de:" << x << ' ' << p[x][i] << '\n';
        if(p[x][i] != -1 && !anc(p[x][i], y))x = p[x][i];
    }
    x = p[x][0];
    cout << x << ' ' << tmp - 2 * dep[x] << '\n';
}

int main(){
    cin.sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    init(n);
    for(int i = 0, x, y; i < q; ++i){
        cin >> x >> y;
        sol(x, y);
    }
}