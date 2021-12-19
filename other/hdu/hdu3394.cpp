#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e4 + 5;
const int MXV = 1e4 + 5;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);
int n, m;
int clash;
int timeCnt, bridge;
vector<int> G[MXV];
vector<int> dep(MXV), low(MXV);
bitset<MXV> inst, isSelected;
stack<int> st;
vector<int> tmp;

void init(int n)
{
    timeCnt = bridge = clash = 0;
    fill(dep.begin(), dep.end(), 0);
    fill(low.begin(), low.end(), 0);
    FOR(i, 0, n + 1) { G[i].clear(); }
    inst.reset();
    while (!st.empty())
    {
        st.pop();
    }
}

void update()
{
    int cnt = 0;
    FOR(u, 0, n + 1) if (isSelected[u])
    {
        FOR(i, 0, G[u].size())
        {
            int v = G[u][i];
            if (isSelected[v])
            {
                ++cnt;
            }
        }
    }
    if (cnt / 2 > (int)tmp.size())
    {
        clash += cnt / 2;
    }
}

void dfs(int u, int f)
{
    dep[u] = low[u] = ++timeCnt;
    st.push(u);
    inst[u] = true;
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i];
        if (v == f)
        {
            continue;
        }
        if (dep[v] == 0)
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dep[u])
            {
                ++bridge;
            }
            if (low[v] >= dep[u])
            {
                int k;
                tmp.clear();
                isSelected.reset();
                do
                {
                    k = st.top();
                    st.pop();
                    tmp.push_back(k);
                    isSelected[k] = true;
                    inst[k] = false;
                } while (k != v);
                tmp.push_back(u);
                isSelected[u] = true;
                update();
            }
        }
        else if (inst[v])
        {
            low[u] = min(low[u], dep[v]);
        }
    }
}

void tarjan(int n)
{
    FOR(i, 0, n)
    {
        if (dep[i] == 0)
        {
            dfs(i, -1);
        }
    }
}

int main()
{
    while (scanf("%d %d", &n, &m), n || m)
    {
        init(n);
        for (int i = 0, x, y; i != m; ++i)
        {
            scanf("%d %d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        tarjan(n);
        printf("%d %d\n", bridge, clash);
    }
}
