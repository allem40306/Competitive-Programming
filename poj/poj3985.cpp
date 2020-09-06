#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 5e5 + 5;
const int MOD = 999997;
typedef pair<int, int> PII;
#define pow2(x) ((x) * (x))
#define MP make_pair
#define PB push_back
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);

struct State
{
    int x, y, step;
    State() {}
    State(int _x, int _y) : x(_x), y(_y), step(0) {}
} s, e, mv[20];
struct Node
{
    int x, y, nxt;
    Node() {}
    Node(int _x, int _y, int _nxt) : x(_x), y(_y), nxt(_nxt) {}
} edge[MXN];
int t, m;
int hashVal[MOD], hi;
double A, B, C, S;
int dis;

int getHash(int x, int y) { return (((x << 13) ^ y) % MOD + MOD) % MOD; }

bool addEdge(int key, int x, int y)
{
    for (int i = hashVal[key]; i != -1; i = edge[i].nxt)
    {
        if (x == edge[i].x && y == edge[i].y)
        {
            return false;
        }
    }
    edge[hi] = Node(x, y, hashVal[key]);
    hashVal[key] = hi++;
    return true;
}

bool ok(int x, int y)
{
    int dis1 = pow2(x - s.x) + pow2(y - s.y);
    int dis2 = pow2(x - e.x) + pow2(y - e.y);
    double dis3 = pow2(A * x + B * y + C) * 1.0 / ((pow2(A) + pow2(B)) * 1.0);
    // cout << dis << ' ' << dis1 << ' ' << dis2 << ' ' << dis3 << ' ' << S
    //      << '\n';
    if (dis + dis1 < dis2 || dis + dis2 < dis1)
    {
        return false;
    }
    if (dis3 <= S)
    {
        return true;
    }
    return false;
}

queue<State> q;
void bfs()
{
    while (!q.empty())
    {
        q.pop();
    }
    q.push(s);
    addEdge(getHash(s.x, s.y), s.x, s.y);
    while (!q.empty())
    {
        State cur = q.front();
        q.pop();
        if (cur.x == e.x && cur.y == e.y)
        {
            printf("%d\n", cur.step);
            return;
        }
        FOR(i, 0, m)
        {
            State tmp = State(cur.x + mv[i].x, cur.y + mv[i].y);
            if (ok(tmp.x, tmp.y) &&
                addEdge(getHash(tmp.x, tmp.y), tmp.x, tmp.y))
            {
                tmp.step = cur.step + 1;
                q.push(tmp);
            }
        }
    }
    printf("IMPOSSIBLE\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d %d", &s.x, &s.y, &e.x, &e.y);
        S = s.step = hi = 0;
        memset(hashVal, -1, sizeof(hashVal));

        A = e.y - s.y;
        B = s.x - e.x;
        C = e.x * s.y - s.x * e.y;
        dis = pow2(e.x - s.y) + pow2(e.y - s.y);
        // cout << A << ' ' << B << ' ' << C << ' ' << T << '\n';
        scanf("%d", &m);
        FOR(i, 0, m)
        {
            scanf("%d %d", &mv[i].x, &mv[i].y);
            S = max(S, (pow2(mv[i].x) + pow2(mv[i].y)) * 1.0);
        }
        bfs();
    }
}