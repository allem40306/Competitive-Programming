#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXV = 5e3 + 5;
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
int timeCnt, sccCnt;
vector<int> sccSz(MXV), sccNo(MXV);
vector<int> dep(MXV), low(MXV);
vector<int> G[MXV];
bitset<MXV> inst;
stack<int> st;

void init(int n, int m)
{
    timeCnt = sccCnt = 0;
    fill(dep.begin(), dep.end(), 0);
    fill(low.begin(), low.end(), 0);
    fill(sccSz.begin(), sccSz.end(), 0);
    fill(sccNo.begin(), sccNo.end(), 0);
    FOR(i, 0, n + 1) { G[i].clear(); }
    inst.reset();
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = 0, x, y; i != m; ++i)
    {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void dfs(int u, int f)
{
    dep[u] = low[u] = ++timeCnt;
    st.push(u);
    inst[u] = true;
    bool flag = 0;
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i];
        if (v == f && !flag)
        {
            flag = true;
            continue;
        }
        if (dep[v] == 0)
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (inst[v])
        {
            low[u] = min(low[u], dep[v]);
        }
    }
    if (dep[u] == low[u])
    {
        int k;
        ++sccCnt;
        do
        {
            k = st.top();
            st.pop();
            inst[k] = false;
            sccNo[k] = sccCnt;
            // cout << k << '\n';
            ++sccSz[sccCnt];
        } while (k != u);
    }
}

void tarjan(int n)
{
    FOR(i, 1, n + 1)
    {
        if (dep[i] == 0)
        {
            dfs(i, -1);
        }
    }
}

int d[MXV];
int sol()
{
    memset(d, 0, sizeof(d));
    FOR(u, 1, n + 1) FOR(j, 0, G[u].size())
    {
        int v = G[u][j];
        if (sccNo[u] != sccNo[v])
        {
            ++d[sccNo[u]];
            ++d[sccNo[v]];
        }
    }
    int ans = 0;
    FOR(i, 1, sccCnt + 1)
    {
        if (d[i] == 2)
        {
            ++ans;
        }
    }
    return ((ans + 1) / 2);
}

int main()
{
    while (scanf("%d %d", &n, &m) != EOF)
    {
        init(n, m);
        tarjan(n);
        printf("%d\n", sol());
    }
}