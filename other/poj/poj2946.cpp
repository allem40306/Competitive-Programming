#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e4 + 5;
const int MXV = 1e4 + 5;
const int MOD = 1000000;
typedef int T;
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
    int x, y;
    int step;
    char ch[10][10];
} cur, tmp, mp[MOD + 5];
int n;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool ok(int x, int y) { return x > 0 && x <= n && y > 0 && y <= n; }

int getHash(const State &state)
{
    int seed = 31, sum = 0;
    FOR(i, 1, n + 1) FOR(j, 1, n + 1)
    {
        if (state.ch[i][j] >= '0' && state.ch[i][j] <= '9')
        {
            sum = sum * seed + (state.ch[i][j] - '0');
            sum %= MOD;
        }
    }
    sum = sum * seed + state.x;
    sum %= MOD;
    sum = sum * seed + state.y;
    sum %= MOD;
    return sum;
}

bool isSame(const State &A, const State &B)
{
    FOR(i, 1, n + 1) FOR(j, 1, n + 1)
    {
        if (A.ch[i][j] != B.ch[i][j])
        {
            return false;
        }
    }
    return A.x == B.x && A.y == B.y;
}

int cnt;
vector<int> v(MOD), nxt(MOD);
bool isUni(const State &state, int k)
{
    for (int i = v[k]; i != -1; i = nxt[i])
    {
        // cout << i << ' ' << v[i] << '\n';
        if (isSame(state, mp[i]))
        {
            return false;
        }
    }
    mp[cnt] = state;
    nxt[cnt] = v[k];
    v[k] = cnt++;
    // cout << k << ' ' << v[k] << '\n';
    return true;
}

bool valueLen(State &state, int d)
{
    int len = 0, num = state.ch[state.x - dir[d][0]][state.y - dir[d][1]] - '0';
    for (int x = state.x, y = state.y; ok(x, y) && state.ch[x][y]=='.'; ++len)
    {
        x += dir[d][0];
        y += dir[d][1];
    }
    if (len < num)
    {
        return false;
    }
    state.ch[state.x - dir[d][0]][state.y - dir[d][1]] = '.';
    for (int x = state.x, y = state.y; ok(x, y) && state.ch[x][y] == '.' && num;
         --num)
    {
        state.ch[x][y] = '1';
        x += dir[d][0];
        y += dir[d][1];
    }
    return true;
}

queue<State> q;
int bfs()
{
    while (!q.empty())
    {
        q.pop();
    }
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.ch[cur.x][cur.y] == 'E')
        {
            return cur.step;
        }
        FOR(i, 0, 4)
        {
            tmp = cur;
            ++tmp.step;
            tmp.x += dir[i][0];
            tmp.y += dir[i][1];
            if (!ok(tmp.x, tmp.y))
            {
                continue;
            }
            if (tmp.ch[tmp.x][tmp.y] != '.')
            {
                int h = getHash(tmp);
                if (isUni(tmp, h))
                {
                    q.push(tmp);
                }
            }
            if (cur.ch[cur.x][cur.y] != '1' && valueLen(tmp, i))
            {
                int h = getHash(tmp);
                if (isUni(tmp, h))
                {
                    q.push(tmp);
                }
            }
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d %d %d", &n, &cur.x, &cur.y), n || cur.x || cur.y)
    {
        cnt = 0;
        fill(v.begin(), v.end(), -1);
        fill(nxt.begin(), nxt.end(), -1);
        cur.step = 0;
        FOR(i, 1, n + 1) { scanf("%s", cur.ch[i] + 1); }
        int ans = bfs();
        if (ans == -1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
}