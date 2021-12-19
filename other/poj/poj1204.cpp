#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int INF = 1e9;
const int MXN = 1e3 + 5;
const int MXW = 26;
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
struct Node
{
    char ch;
    int id;
    Node *next[MXW];
    Node *fail;
    Node() : id(-1), fail(0) { memset(next, 0, sizeof(next)); }
};
int L, C, W;
int len[MXN];
int ans[MXN][3];
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                 {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
char mp[MXN][MXN];

void insert(Node *root, char *s, int id)
{
    int sz = strlen(s);
    FOR(i, 0, sz)
    {
        int v = s[i] - 'A';
        if (root->next[v] == NULL)
        {
            root->next[v] = new Node();
        }
        root = root->next[v];
        root->ch = s[i];
    }
    root->id = id;
}

queue<Node *> q;
void bulidAC(Node *root)
{
    Node *k, *tmp;
    FOR(i, 0, MXW)
    {
        if (root->next[i] != NULL)
        {
            root->next[i]->fail = root;
            q.push(root->next[i]);
        }
    }
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        FOR(i, 0, MXW) if (k->next[i] != NULL)
        {
            tmp = k->fail;
            while (tmp != NULL)
            {
                if (tmp->next[i] != NULL)
                {
                    k->next[i]->fail = tmp->next[i];
                    break;
                }
                tmp = tmp->fail;
            }
            if (tmp == NULL)
            {
                k->next[i]->fail = root;
            }
            q.push(k->next[i]);
        }
    }
}

bool ok(int x, int y) { return x >= 0 && x < L && y >= 0 && y < C; }

void acAutomation(Node *root, int x, int y, int d)
{
    Node *p = root;
    while (ok(x, y))
    {
        int v = mp[x][y] - 'A';
        while (p->next[v] == NULL && p != root)
        {
            p = p->fail;
        }
        p = p->next[v];
        if (p == NULL)
        {
            p = root;
        }
        Node *k = p;
        while (k != root)
        {
            if (k->id >= 0)
            {
                int id = k->id;
                ans[id][0] = x - len[id] * dir[d][0];
                ans[id][1] = y - len[id] * dir[d][1];
                ans[id][2] = d;
                k->id = -1;
            }
            else
            {
                break;
            }
            k = k->fail;
        }
        x += dir[d][0];
        y += dir[d][1];
    }
}

char s[MXN];
int main()
{
    scanf("%d %d %d", &L, &C, &W);
    Node *root = new Node();
    FOR(i, 0, L) { scanf("%s", mp[i]); }
    FOR(i, 0, W)
    {
        scanf("%s", s);
        insert(root, s, i);
        len[i] = strlen(s) - 1;
    }
    bulidAC(root);
    FOR(dir, 0, 8) FOR(i, 0, L)
    {
        acAutomation(root, i, 0, dir);
        acAutomation(root, i, C - 1, dir);
    }
    FOR(dir, 0, 8) FOR(i, 0, C)
    {
        acAutomation(root, 0, i, dir);
        acAutomation(root, L - 1, i, dir);
    }
    FOR(i, 0, W)
    {
        printf("%d %d %c\n", ans[i][0], ans[i][1], char(ans[i][2] + 'A'));
    }
}