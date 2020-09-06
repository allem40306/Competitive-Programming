#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int INF = 1e9;
const int MXN = 3e5 + 5;
const int MXS = 1e7 + 5;
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
    int v;
    Node *next[MXW];
    Node *fail;
    Node(): v(0), fail(0) { memset(next,0,sizeof(next)); }
};

void insert(Node *root, char *s)
{
    int sz = strlen(s);
    FOR(i, 0, sz)
    {
        int v = s[i] - 'a';
        if (root->next[v] == NULL)
        {
            root->next[v] = new Node();
        }
        root = root->next[v];
        root->ch = s[i];
    }
    ++root->v;
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

int ans;
void acAutomation(Node *root, char *s)
{
    Node *p = root;
    int sz = strlen(s);
    FOR(i, 0, sz)
    {
        int v = s[i] - 'a';
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
            if (k->v >= 0)
            {
                ans += k->v;
                k->v = -1;
            }
            else
            {
                break;
            }
            k = k->fail;
        }
    }
}

char s[MXS];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        Node *root =  new Node();
        scanf("%d", &n);
        while (n--)
        {
            scanf("%s", s);
            insert(root, s);
        }
        bulidAC(root);
        scanf("%s", s);
        ans = 0;
        acAutomation(root, s);
        printf("%d\n", ans);
    }
}