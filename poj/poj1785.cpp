#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;
const int INF = 1e9;
const int MXN = 5e4 + 5;
const int MXS = 1e2 + 5;
const LL MOD = 10009;
const LL seed = 31;
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
char s[MXN][MXS];
struct Node
{
    int key, val;
    int Lc, Rc, p;
    bool operator<(const Node &rhs) const
    {
        return strcmp(s[key], s[rhs.key]) < 0;
    }
} node[MXN];

void insert(int x)
{
    int y = x - 1;
    while (node[y].val < node[x].val)
    {
        y = node[y].p;
    }
    node[x].Lc = node[y].Rc;
    node[node[x].Lc].p = x;
    node[y].Rc = x;
    node[x].p = y;
}

void dfs(int x)
{
    if (x == 0)
    {
        return;
    }
    printf("(");
    dfs(node[x].Lc);
    printf("%s/%d", s[node[x].key], node[x].val);
    dfs(node[x].Rc);
    printf(")");
}

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        FOR(i, 1, n + 1)
        {
            scanf(" %[a-z]/%d", s[i], &node[i].val);
            node[i].key = i;
            // printf("%s-%d\n", s[i], node[i].val);
        }
        sort(node + 1, node + n + 1);
        node[0].val = INF;
        node[0].Lc = node[0].Rc = node[0].p = 0;
        FOR(i, 0, n + 1)
        {
            node[i].Lc = node[i].Rc = node[i].p = 0;
            insert(i);
        }
        dfs(node[0].Rc);
        printf("\n");
    }
}