#pragma GCC optimize(2)
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e6 + 5;
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
struct Treap
{
    int key, val, pri, sz;
    Treap *lc, *rc;
    Treap() {}
    Treap(int _key, int _val)
    {
        key = _key;
        val = _val;
        pri = rand();
        sz = 1;
        lc = rc = NULL;
    }
};

int getSize(Treap *a) { return (a == NULL ? 0 : a->sz); }

void split(Treap *t, Treap *&a, Treap *&b, int k)
{
    if (t == NULL)
    {
        a = b = NULL;
        return;
    }
    // cout << t->key << ' ' << k << '\n';
    if (t->key <= k)
    {
        a = t;
        split(t->rc, a->rc, b, k);
    }
    else
    {
        b = t;
        split(t->lc, a, b->lc, k);
    }
}

Treap *merge(Treap *a, Treap *b)
{
    if (!a || !b)
    {
        return (a ? a : b);
    }
    if (a->pri > b->pri)
    {
        a->rc = merge(a->rc, b);
        return a;
    }
    else
    {
        b->lc = merge(a, b->lc);
        return b;
    }
}

void Insert(Treap *&t, int key, int val)
{
    // cout << "ins " << key << ' ' << val << '\n';
    Treap *a, *b;
    split(t, a, b, key);
    t = merge(a, merge(new Treap(key, val), b));
}

void Delete(Treap *&t, int val)
{
    // cout << "del " << val << '\n';
    Treap *a, *b, *c;
    split(t, b, c, val);
    split(b, a, b, val - 1);
    t = merge(a, c);
}

int find(Treap *t, int x)
{
    if (x)
    {
        if (t->lc)
        {
            return find(t->lc, x);
        }
    }
    else
    {
        if (t->rc)
        {
            return find(t->rc, x);
        }
    }
    printf("%d\n", t->val);
    return t->key;
}

int main()
{
    Treap *root = NULL;
    int cmd;
    while (scanf("%d", &cmd), cmd)
    {
        if (cmd == 1)
        {
            int k, p;
            scanf("%d %d", &k, &p);
            Insert(root, p, k);
        }
        else
        {
            if (root == NULL)
            {
                printf("%d\n", 0);
                continue;
            }
            int key = find(root, cmd - 2);
            Delete(root, key);
        }
    }
}