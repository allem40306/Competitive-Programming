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
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MOD = 999997;
typedef pair<int, int> PII;
#define Fi first
#define Se second
#define MP make_pair
#define PB push_back
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);

int vis[MXN], step[MXN];
vector<int> v(3);

void bfs(int s, int e)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    step[s] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == e)
        {
            printf("%d\n", step[e]);
            return;
        }
        v[0] = cur + 1;
        v[1] = cur - 1;
        v[2] = cur * 2;
        FOR(i, 0, 3) if (!vis[v[i]] && v[i] >= 0 && v[i] <= 100000)
        {
            q.push(v[i]);
            vis[v[i]] = 1;
            step[v[i]] = step[cur] + 1;
        }
    }
}

int main()
{
    int s, e;
    while (scanf("%d %d", &s, &e) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        bfs(s, e);
    }
}