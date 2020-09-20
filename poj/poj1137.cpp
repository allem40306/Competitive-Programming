#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 105;
const int MXV = 105;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
struct State
{
    int room, Light, step;
    string ans;
    State() {}
    State(int _room, int _Light, int _step, string _ans)
        : room(_room), Light(_Light), step(_step), ans(_ans)
    {
    }
};
int r, d, s;
vector<int> LG[MXV], RG[MXV];
bool vis[MXV][(1 << 12)];

void init()
{
    memset(vis, 0, sizeof(vis));
    FOR(i, 0, MXV)
    {
        LG[i].clear();
        RG[i].clear();
    }
}

void bfs()
{
    queue<State> q;
    State tmp(1, 1, 0, "");
    q.push(tmp);
    while (!q.empty())
    {
        State cur = q.front();
        q.pop();
        // printf("cur: %d %x\n", cur.room, cur.Light);
        if (cur.Light == (1 << (r - 1)) && cur.room == r)
        {
            printf("The problem can be solved in %d steps:\n", cur.step);
            for (int i = 0; i != (int)cur.ans.size(); i += 2)
            {
                if (cur.ans[i] == 'M')
                {
                    printf("- Move to room %d.\n", int(cur.ans[i + 1]));
                }
                if (cur.ans[i] == 'N')
                {
                    printf("- Switch on light in room %d.\n",
                           int(cur.ans[i + 1]));
                }
                if (cur.ans[i] == 'F')
                {
                    printf("- Switch off light in room %d.\n",
                           int(cur.ans[i + 1]));
                }
            }
            return;
        }
        FOR(i, 0, RG[cur.room].size())
        {
            int v = RG[cur.room][i];
            // cout << v << ':' << cur.Light << '\n';
            if (!vis[v][cur.Light] && ((1 << (v - 1)) & cur.Light))
            {
                tmp = State(v, cur.Light, cur.step + 1, cur.ans + "M");
                tmp.ans += char(v);
                q.push(tmp);
                // cout << tmp.room << '-' << tmp.Light << '\n';
                vis[tmp.room][tmp.Light] = true;
            }
        }
        FOR(i, 0, LG[cur.room].size())
        {
            int v = LG[cur.room][i];
            tmp.room = cur.room;
            tmp.Light = cur.Light & (((1 << 10) - 1) ^ (1 << (v - 1)));
            if (!vis[tmp.room][tmp.Light] && cur.room != v)
            {
                tmp = State(tmp.room, tmp.Light, cur.step + 1, cur.ans + "F");
                tmp.ans += char(v);
                q.push(tmp);
                // cout << tmp.room << '/' << tmp.Light << '\n';
                vis[tmp.room][tmp.Light] = true;
            }
        }
        FOR(i, 0, LG[cur.room].size())
        {
            int v = LG[cur.room][i];
            tmp.room = cur.room;
            tmp.Light = cur.Light | (1 << (v - 1));
            if (!vis[tmp.room][tmp.Light])
            {
                tmp = State(tmp.room, tmp.Light, cur.step + 1, cur.ans + "N");
                tmp.ans += char(v);
                q.push(tmp);
                // cout << tmp.room << '_' << tmp.Light << '\n';
                vis[tmp.room][tmp.Light] = true;
            }
        }
    }
    printf("The problem cannot be solved.\n");
}

int main()
{
    int ti = 0;
    while (scanf("%d %d %d", &r, &d, &s), r || d || s)
    {
        init();
        FOR(i, 0, d)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            RG[x].push_back(y);
            RG[y].push_back(x);
        }
        FOR(i, 0, s)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            LG[x].push_back(y);
        }
        FOR(i, 1, r + 1)
        {
            sort(RG[i].begin(), RG[i].end());
            sort(LG[i].begin(), LG[i].end());
        }
        printf("Villa #%d\n", ++ti);
        bfs();
        printf("\n");
    }
}