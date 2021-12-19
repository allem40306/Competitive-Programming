#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e3 + 5;
const int MXV = 1e3 + 5;
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
int timeCnt, bccCnt;
bool canJoin[MXV], notOK[MXV][MXV];
vector<int> bccSz(MXV), bccNo(MXV);
vector<int> dep(MXV), low(MXV);
vector<int> G[MXV];
vector<int> tmp;
vector<int> color(MXV);
bitset<MXV> inst;
stack<int> st;

void init(int n)
{
    timeCnt = bccCnt = 0;
    fill(bccSz.begin(), bccSz.end(), 0);
    fill(bccNo.begin(), bccNo.end(), 0);
    fill(dep.begin(), dep.end(), 0);
    fill(low.begin(), low.end(), 0);
    memset(notOK, 0, sizeof(notOK));
    memset(canJoin, 0, sizeof(canJoin));
    FOR(i, 1, n + 1) { G[i].clear(); }
    inst.reset();
    while (!st.empty())
    {
        st.pop();
    }
}

bool isOddCycle(int u, int c)
{
    color[u] = c;
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i];
        if (bccNo[u] != bccNo[v])
        {
            continue;
        }
        if ((color[v] == 0 && isOddCycle(v, 1 - c)) ||
            (color[v] != 0 && color[v] == color[u]))
        {
            return true;
        }
    }
    return false;
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
            if (low[v] >= dep[u])
            {
                int k;
                ++bccCnt;
                tmp.clear();
                do
                {
                    k = st.top();
                    st.pop();
                    inst[k] = false;
                    bccNo[k] = bccCnt;
                    tmp.push_back(k);
                    ++bccSz[bccCnt];
                } while (k != v);
                bccNo[u] = bccCnt;
                ++bccSz[bccCnt];
                fill(color.begin(), color.end(), 0);
                tmp.push_back(u);
                if ((int)tmp.size() >= 3 && isOddCycle(u, 0))
                {
                    FOR(i, 0, tmp.size()) { canJoin[tmp[i]] = true; }
                }
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
    FOR(i, 1, n + 1)
    {
        if (dep[i] == 0)
        {
            dfs(i, -1);
        }
    }
}

int sol()
{
    int ans = n;
    FOR(i, 1, n + 1) if (canJoin[i]) { --ans; }
    return ans;
}

int main()
{
    while (scanf("%d %d", &n, &m), n || m)
    {
        init(n);
        for (int i = 0, x, y; i != m; ++i)
        {
            scanf("%d %d", &x, &y);
            notOK[x][y] = notOK[y][x] = true;
        }
        FOR(i, 1, n + 1) FOR(j, 1, n + 1)
        {
            if (i != j && notOK[i][j] == false)
            {
                G[i].push_back(j);
            }
        }
        tarjan(n);
        printf("%d\n", sol());
    }
}
