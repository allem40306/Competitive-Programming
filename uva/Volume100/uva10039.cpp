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
const int MXV = 105;
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
    int from, to;
    int t1, t2;
    Edge(){};
    Edge(int _from, int _to, int _t1, int _t2)
        : from(_from), to(_to), t1(_t1), t2(_t2){};
};
map<string, int> city;
vector<Edge> E;
vector<int> G[MXV];

void addEdge(int from, int to, int t1, int t2)
{
    G[from].emplace_back(E.size());
    // G[to].emplace_back(E.size());
    E.emplace_back(from, to, t1, t2);
}

int dp[MXV][2500];

void solve(int n, int start_time, string start_city, string destination_city)
{
    int s = city[start_city], t = city[destination_city];
    memset(dp, -1, sizeof(dp));
    for (int idx : G[s])
    {
        Edge &e = E[idx];
        if (e.t1 >= start_time)
        {
            dp[e.to][e.t2] = e.t1;
            // cout << e.to << ',' << e.t2 << ' ' << dp[e.to][e.t2] << '\n';
        }
    }
    FOR(i, 0, 2400 + 1) FOR(j, 0, n) if (dp[j][i] != -1)
    {
        for (int idx : G[j])
        {
            Edge &e = E[idx];
            if (e.t1 >= i)
            {
                dp[e.to][e.t2] = max(dp[e.to][e.t2], dp[j][i]);
                // cout << j << ' ' << i << '\n';
                // cout << e.to << ',' << e.t2 << ' ' << dp[e.to][e.t2] << '\n';
            }
        }
    }
    FOR(i, 0, 2400 + 1) if (dp[t][i] != -1)
    {
        cout << "Departure " << setw(4) << setfill('0');
        cout << dp[t][i] << ' ' << start_city << '\n';
        cout << "Arrival   " << setw(4) << setfill('0');
        cout << i << ' ' << destination_city << '\n';
        return;
    }
    cout << "No connection\n";
}

int main()
{
    IOS;
    int T;
    cin >> T;
    FOR(Ti, 1, T + 1)
    {
        int c, t;
        cin >> c;
        city.clear();
        FOR(i, 0, c)
        {
            string s;
            cin >> s;
            city[s] = i;
        }
        cin >> t;
        E.clear();
        FOR(i, 0, MXV) G[i].clear();
        FOR(i, 0, t)
        {
            int x, t1, t2;
            string s1, s2;
            cin >> x >> t1 >> s1;
            while (--x)
            {
                cin >> t2 >> s2;
                addEdge(city[s1], city[s2], t1, t2);
                t1 = t2;
                s1 = s2;
            }
        }
        int start_time;
        string start_city, destination_city;
        cin >> start_time >> start_city >> destination_city;
        cout << "Scenario " << Ti << '\n';
        solve(c, start_time, start_city, destination_city);
        cout << '\n';
    }
}
