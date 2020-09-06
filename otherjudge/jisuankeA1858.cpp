#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int INF = 1e9;
const int MXN = 3e5 + 5;
const int MXS = 1e6 + 5;
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
    int nodei;
    char ch[MXS];
    int sz[MXS];
    int trie[MXS][MXW];
    int fail[MXS];
    void init() { nodei = -1; }
    int newNode()
    {
        ++nodei;
        fail[nodei] = -1;
        sz[nodei] = 0;
        memset(trie[nodei], -1, sizeof(trie[nodei]));
        return nodei;
    }
    // Node() { init(); }
} node;

void insert(int root, char *s, int id)
{
    int sz = strlen(s);
    FOR(i, 0, sz)
    {
        int v = s[i] - 'a';
        if (node.trie[root][v] == -1)
        {
            node.trie[root][v] = node.newNode();
        }
        root = node.trie[root][v];
        node.ch[root] = s[i];
    }
    node.sz[root] = strlen(s);
}

queue<int> q;
void bulidAC(int root)
{
    int k, tmp;
    FOR(i, 0, MXW)
    {
        if (node.trie[root][i] != -1)
        {
            node.fail[node.trie[root][i]] = root;
            q.push(node.trie[root][i]);
        }
    }
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        node.sz[k] = max(node.sz[k], node.sz[node.fail[k]]);
        FOR(i, 0, MXW) if (node.trie[k][i] != -1)
        {
            tmp = node.fail[k];
            while (tmp != -1)
            {
                if (node.trie[tmp][i] != -1)
                {
                    node.fail[node.trie[k][i]] = node.trie[tmp][i];
                    break;
                }
                tmp = node.fail[tmp];
            }
            if (tmp == -1)
            {
                node.fail[node.trie[k][i]] = root;
            }
            q.push(node.trie[k][i]);
        }
    }
}

int len[MXS], hideEnd[MXS];
void acAutomation(int root, char *s)
{
    int p = root;
    memset(hideEnd, -1, sizeof(hideEnd));
    int sz = strlen(s);
    FOR(i, 0, sz)
    {
        if (!isalpha(s[i]))
        {
            p = root;
            continue;
        }
        int v = tolower(s[i]) - 'a';
        while (node.trie[p][v] == -1 && p != root)
        {
            p = node.fail[p];
        }
        p = node.trie[p][v];
        if (p == -1)
        {
            p = root;
        }
        int k = p;
        while (k != root)
        {
            if (node.sz[k] > 0)
            {
                hideEnd[i - node.sz[k] + 1] = i;
            }
            else
            {
                break;
            }
            k = node.fail[k];
        }
    }
    int tmp = -1;
    FOR(i, 0, sz)
    {
        tmp = max(tmp, hideEnd[i]);
        if (i<=tmp)
        {
            printf("*");
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

char s[MXS];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        node.init();
        int root = node.newNode();
        scanf("%d", &n);
        FOR(i, 0, n)
        {
            scanf("%s", s);
            len[i] = strlen(s);
            insert(root, s, i);
        }
        bulidAC(root);
        char ch;
        while ((ch = getchar()) != '\n')
            ;
        gets(s);
        acAutomation(root, s);
    }
}