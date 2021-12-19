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
int sccCnt;
int sccSz[MXV], sccNo[MXV];
vector<int> G[MXV], TG[MXV], leave;
bitset<MXV> visit;

void init(int n, int m)
{
    sccCnt = 0;
    memset(sccSz, 0, sizeof(sccSz));
    memset(sccNo, 0, sizeof(sccNo));
    for (int i = 1; i <= n; ++i)
    {
        G[i].clear();
        TG[i].clear();
    }
    leave.clear();
    visit.reset();
    for (int i = 0, x, y; i != m; ++i)
    {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        TG[y].push_back(x);
    }
}

void dfsForStamp(int u)
{
    visit[u] = true;
    FOR(i, 0, G[u].size())
    {
        int v = G[u][i];
        if (!visit[v])
        {
            dfsForStamp(v);
        }
    }
    leave.push_back(u);
}

void dfsForScc(int u, int cnt)
{
    visit[u] = true;
    ++sccSz[cnt];
    sccNo[u] = cnt;
    FOR(i, 0, TG[u].size())
    {
        int v = TG[u][i];
        if (!visit[v])
        {
            dfsForScc(v, cnt);
        }
    }
}

void kosaraju(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!visit[i])
        {
            dfsForStamp(i);
        }
    }
    visit.reset();
    for (int i = leave.size() - 1; i >= 0; --i)
    {
        int u = leave[i];
        if (!visit[u])
        {
            ++sccCnt;
            dfsForScc(u, sccCnt);
        }
    }
}

int dout[MXV];
int sol()
{
    memset(dout, 0, sizeof(dout));
    FOR(u, 1, n + 1) FOR(j, 0, TG[u].size())
    {
        int v = TG[u][j];
        if (sccNo[u] == sccNo[v])
        {
            continue;
        }
        ++dout[sccNo[v]];
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
    return sccSz[popular];
}

int main()
{
    scanf("%d %d", &n, &m);
    init(n, m);
    kosaraju(n);
    printf("%d\n", sol());
}