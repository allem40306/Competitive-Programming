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
int timeCnt, sccCnt;
vector<int> sccSz(MXV), sccNo(MXV);
vector<int> dep(MXV), low(MXV);
vector<int> G[MXV];
bitset<MXV> inst;
stack<int> st;

void init(int n, int m)
{
    timeCnt = sccCnt = 0;
    fill(sccSz.begin(), sccSz.end(), 0);
    fill(sccNo.begin(), sccNo.end(), 0);
    FOR(i, 1, n + 1) { G[i].clear(); }
    inst.reset();
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = 0, x, y; i != m; ++i)
    {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
    }
}

void dfs(int u)
{
    dep[u] = low[u] = ++timeCnt;
    st.push(u);
    inst[u] = true;
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i];
        if (dep[v] == 0)
        {
            dfs(v);
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
        // cout << sccCnt << ':' << '\n';
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
            dfs(i);
        }
    }
}

int dout[MXV];
int sol()
{
    memset(dout, 0, sizeof(dout));
    FOR(u, 1, n + 1) FOR(j, 0, G[u].size())
    {
        int v = G[u][j];
        if (sccNo[u] == sccNo[v])
        {
            continue;
        }
        ++dout[sccNo[u]];
    }
    int popular = -1;
    FOR(i, 1, sccCnt + 1)
    {
        if (dout[i])
        {
            continue;
        }
        if (popular != -1)
        {
            return 0;
        }
        popular = i;
    }
    int ans = 0;
    FOR(u, 1, n + 1)
    {
        if (sccNo[u] == popular)
        {
            ++ans;
        }
    }
    return ans;
}

int main()
{
    scanf("%d %d", &n, &m);
    init(n, m);
    tarjan(n);
    printf("%d\n", sol());
}