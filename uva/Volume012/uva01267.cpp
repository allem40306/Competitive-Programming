#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> G[N], nodes[N];
int n, s, k, p[N];
bitset<N> c;

void init(int n){
    for(int i = 1; i <= n; ++i){
        G[i].clear();
        nodes[i].clear();
    }
    for(int i = 1, a, b; i < n; ++i){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

void dfs1(int u, int f, int w){
    p[u] = f;
    if(G[u].size() == 1 && w > k){
        nodes[w].push_back(u);
    }
    for(int v: G[u]){
        if(v != f)dfs1(v, u, w + 1);
    }
}

void dfs2(int u, int f, int w){
    c[u] = true;
    for(int v: G[u]){
        if(v != f && w < k)dfs2(v, u, w + 1);
    }
}

int sol(){
    int ans = 0;
    c.reset();
    for(int w = n - 1; w > k; --w){
        for(int u: nodes[w]){
            if(c[u])continue; 
            int v = u;
            for(int i = 0; i < k; ++i)v = p[v];
            dfs2(v, -1, 0);
            ans++;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s >> k;
        init(n);
        dfs1(s, -1, 0);
        cout << sol() << '\n';
    }
} 
