#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 1005;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

struct Edge
{
    int t;
    long long w;
    Edge(){};
    Edge(int _t, long long _w) : t(_t), w(_w) {}
};

int n;
long long dis[MXV];
vector<Edge> G[MXV];

void init()
{
    for (int i = 0; i < MXV; i++)
    {
        G[i].clear();
        dis[i] = INF;
    }
}

bool SPFA(int st)
{
    vector<int> cnt(n, 0);
    bitset<MXV> inq(0);
    queue<int> q;

    q.push(st);
    dis[st] = 0;
    inq[st] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        inq[cur] = false;
        for (auto &e : G[cur])
        {
            if (dis[e.t] <= dis[cur] + e.w)
                continue;
            dis[e.t] = dis[cur] + e.w;
            if (inq[e.t])
                continue;
            ++cnt[e.t];
            if (cnt[e.t] > n)
                return false; // negtive cycle
            inq[e.t] = true;
            q.push(e.t);
        }
    }
    return true;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        init();
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            int s, t;
            long long w;
            cin >> s >> t >> w;
            G[s].emplace_back(t, w);
        }
        if (!SPFA(0))
        {
            cout << "possible\n";
        }
        else
        {
            cout << "not possible\n";
        }
    }
}