#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;
const LL INF = (1 << 29);
const int MXN = 5e4 + 5;
const int MXV = 0;
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
struct Node
{
    int v, ch[2], f;
} node[MXN];
int root, sz, n, m;
bool isDestroy[MXN];

void dfs(int u)
{
    if (!u)
    {
        return;
    }
    cout << '(';
    dfs(node[u].ch[0]);
    cout << ')';
    cout << node[u].v;
    cout << '(';
    dfs(node[u].ch[1]);
    cout << ')';
}

bool get(int x) { return x == node[node[x].f].ch[1]; }

void rotate(int x)
{
    int y = node[x].f, z = node[y].f;
    bool dir = (node[y].ch[1] == x);
    node[y].ch[dir] = node[x].ch[dir ^ 1];
    if (node[y].ch[dir])
    {
        node[node[y].ch[dir]].f = y;
    }
    node[x].ch[dir ^ 1] = y;
    node[y].f = x;
    node[x].f = z;
    if (z)
    {
        node[z].ch[node[z].ch[1] == y] = x;
    }
}

void splay(int x, int tp)
{
    for (int y, z; (y = node[x].f) != tp; rotate(x))
    {
         z = node[y].f;
        if (z != tp)
        {
            rotate(((node[z].ch[0] == y) == (node[y].ch[0] == x)) ? y : x);
        }
    }
    if (!tp)
    {
        root = x;
    }
}

void insert(int t, int x)
{
    int y = 0;
    while (t && node[t].v != x)
    {
        y = t;
        t = node[t].ch[(x > node[t].v)];
    }
    t = ++sz;
    node[t].v = x;
    node[t].f = y;
    if (y)
    {
        node[y].ch[(x > node[y].v)] = t;
    }
    splay(t, 0);
}

void find(int v)
{
    int x = root;
    if (x == 0)
    {
        return;
    }
    while (node[x].ch[(v > node[x].v)] && node[x].v != v)
    {
        x = node[x].ch[(v > node[x].v)];
    }
    splay(x, 0);
}

int nxt(int x, bool dir)
{
    find(x);
    if ((node[root].v > x && dir) || (node[root].v < x && !dir))
    {
        return root;
    }
    int p = node[root].ch[dir];
    while (node[p].ch[dir ^ 1])
    {
        p = node[p].ch[!dir];
    }
    return p;
}

void Delete(int v)
{
    int p = nxt(v, 0), s = nxt(v, 1);
    splay(p, 0);
    splay(s, p);
    p = node[s].ch[0];
    node[s].ch[0] = 0;
}

int main()
{
    int n, m;
    stack<int> st;
    scanf("%d %d", &n, &m);
    char cmd[3];
    int x;
    insert(root, 0);
    insert(root, n + 1);
    while (m--)
    {
        scanf("%s", cmd);
        if (cmd[0] == 'D')
        {
            scanf("%d", &x);
            isDestroy[x] = true;
            st.push(x);
            insert(root, x);
        }
        else if (cmd[0] == 'Q')
        {
            scanf("%d", &x);
            if (isDestroy[x])
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", node[nxt(x, 1)].v - node[nxt(x, 0)].v - 1);
            }
        }
        else
        {
            x = st.top();
            st.pop();
            Delete(x);
            isDestroy[x] = 0;
        }
    }
}