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
const int MXN = 1e5 + 5;
const int MXV = 1e5 + 5;
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
bool ok;

struct Node
{
    int i;
    char ch;
    int v;
    Node *next[10];
    void init(char _ch = '\0')
    {
        v = 0;
        FOR(i, 0, 10) next[i] = NULL;
    }
    Node() { init(); }
} node[MXN];
int nodei;
char s[MXN][15];

void insert(Node *root, string s)
{
    FOR(i, 0, s.size())
    {
        int v = s[i] - '0';
        if (root->next[v] == NULL)
        {
            root->next[v] = &node[++nodei];
            root->next[v]->init();
        }
        root = root->next[v];
        root->ch = s[i];
        ++root->v;
    }
    return;
}

void search(Node *root, string s)
{
    FOR(i, 0, s.size())
    {
        int v = s[i] - '0';
        root = root->next[v];
    }
    if (root->v > 1)
    {
        ok = false;
    }
}

int main()
{
    FOR(i, 0, MXN) { node[i].i = i; }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        Node *root = &node[0];
        scanf("%d", &n);
        root->init();
        nodei = 0;
        FOR(i, 0, n)
        {
            scanf("%s", s[i]);
            insert(root, s[i]);
        }
        ok = true;
        FOR(i, 0, n)
        {
            search(root, s[i]);
            if (!ok)
            {
                break;
            }
        }
        if (ok)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}