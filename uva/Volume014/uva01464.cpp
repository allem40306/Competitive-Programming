#include <bits/stdc++.h>
using namespace std;
const int MXN = 10005;
const int MXM = 100005;
typedef pair<int,int> PII;
int n, m, cnt;
int first[MXN], jump[MXM << 1], to[MXM << 1];
int low[MXN], depth[MXN], bccno[MXN], cntbcc = 0, eccno[MXM];
bitset<MXN> iscut, visit;
vector<int> BCC[MXN], G[MXN << 1];
stack<PII> st;

void addEdge(int u, int v){
    jump[cnt] = first[u];
    to[cnt] = v;
    first[u] = cnt++; 
}

void dfs(int now, int cur_depth, int f){
	visit[now] = true;
	depth[now] = low[now] = cur_depth;
	int cut_son = 0;
	for (int it = first[now]; it != -1; it = jump[it]){
        int i = to[it];
        if(i == f)continue;
		if(visit[i]){// ancestor
			if (depth[i] < depth[now]){
			    low[now] = min(low[now], depth[i]);
                st.push({now ,i});
            }
		}else{// offspring
            st.push({now ,i});
            cut_son += 1;
			dfs(i, cur_depth + 1, now);
            low[now] = min(low[now], low[i]);
			if (low[i] >= depth[now]){
				iscut[now] = true;
                BCC[++cntbcc].clear();
                PII t = st.top(); st.pop();
                while(1){
                    if(bccno[t.first] != cntbcc){
                        bccno[t.first] = cntbcc;
                        BCC[cntbcc].push_back(t.first);
                    }
                    if(bccno[t.second] != cntbcc){
                        bccno[t.second] = cntbcc;
                        BCC[cntbcc].push_back(t.second);
                    }
                    if(t == make_pair(now ,i))break;
                    t = st.top(); st.pop();
                }
            }
		}
	}
	if (cur_depth == 0)iscut[now] = (cut_son > 1);
	return;
}

void init(){
    cnt = 0;
    memset(first, -1, sizeof(first));
    for(int i = 0, u, v; i < m; ++i){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    // find BCC
    memset(low, -1, sizeof(low));
    memset(bccno, 0, sizeof(bccno));
    iscut.reset();
    visit.reset();
    cntbcc = 0;
    for(int i = 1; i < n; ++i){
        if(visit[i] == false)dfs(i, 0, -1);
    }
    for(int i = 1; i <= cntbcc; ++i){
        G[i].clear();
        for(auto it: BCC[i]){
            bccno[it] = i;
        }
        for(auto it: BCC[i]){
            for(int p = first[it]; p != -1; p = jump[p]){
                if(bccno[to[p]] == i){
                    eccno[p >> 1] = i;
                }
            }
        }
    }

    int c = 0;
    vector<int> tmp;
    for(int i = 1; i <= n; ++i){
        if(!iscut[i])continue;
        ++c;
        G[cntbcc + c].clear();
        tmp.clear();
        for(int j = first[i]; j != -1; j = jump[j]){
            tmp.push_back(eccno[j >> 1]);
        }
        sort(tmp.begin(), tmp.end());
        tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());

        for(int j = 0; j < (int)tmp.size(); ++j){
            G[cntbcc + c].push_back(tmp[j]);
            G[tmp[j]].push_back(cntbcc + c);
        }
    }
    n = cntbcc + c;
}

const int LOG = 20;
bitset<MXN << 1> vis;
int par[MXN << 1][LOG], dep[MXN << 1];
int timer = 0, tin[MXN << 1], tout[MXN << 1];

void LCAdfs(int p, int f, int d){
    tin[p] = ++timer;
    dep[p] = d;
    par[p][0] = f;
    vis[p] = true;
    for(auto it: G[p]){
        if(!vis[it])LCAdfs(it, p, d + 1);
    }
    tout[p] = ++timer;
}

void Doubling(){
    for(int j = 1; j < LOG; ++j){
        for(int i = 1; i <= n; ++i){
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

void LCAinit(){
    timer = 0;
    vis.reset();
    for(int i = 1; i <= n; ++i){
        if(!vis[i])LCAdfs(i, i, 0);
    }
    Doubling();
}

bool anc(int u, int v){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int LCA(int u, int v){
    if(dep[u] > dep[v])swap(u, v);
    if(anc(u, v))return u;
    for(int j = LOG - 1; j >= 0; --j){
        if(!anc(par[u][j], v))u = par[u][j];
    }
    return par[u][0];
}

int main(){
    int q;
    while(cin >> n >> m, n || m){
        init();
        LCAinit();
        cin >> q;
        for(int i = 0, u, v, lca; i != q; ++i){
            cin >> u >> v;
            u = eccno[u - 1];
            v = eccno[v - 1];
            lca = LCA(u, v);
            cout << ((dep[u] + dep[v] - 2 * dep[lca]) >> 1) << '\n';
        }
    }
}