#include <iostream>
#include <cstdlib>
using namespace std;
struct Treap{
    int val, pri, sz;
    int add, mn;
    bool rev;
    Treap *lc, *rc;
    Treap(){}
    Treap(int _val)
    {
        val = mn = _val;
        pri = rand();
        sz = 1;
        add = 0;
        rev = false;
        lc = rc = NULL;
    }
    void push();
    void pull();
};

void dfs(Treap *&t)
{
    cout << t->val;
    cout << '(';
    if(t->lc)dfs(t->lc);
    cout << '|';
    if(t->rc)dfs(t->rc);
    cout << ')';
}

int getSize(Treap *a){
    return (a == NULL ? 0 : a->sz);
}

void Treap::push()
{
    if(rev == true)
    {
        if(lc != NULL)
        {
            swap(lc->lc, lc->rc);
            lc->rev = !lc->rev;
        }
        if(rc != NULL)
        {
            swap(rc->lc, rc->rc);
            rc->rev = !rc->rev;
        }
        rev = false;
    }
    if(add != 0)
    {
        if(lc != NULL)
        {
            lc->val += add;
            lc->add += add;
            lc->mn += add;
        }
        if(rc != NULL)
        {
            rc->val += add;
            rc->add += add;
            rc->mn += add;
        }
        add = 0;
    }
}

void Treap::pull()
{
    sz = getSize(lc) + getSize(rc) + 1;
    mn = val;
    if(lc != NULL)
    {
        mn = min(mn, lc->mn);
    }
    if(rc != NULL)
    {
        mn = min(mn, rc->mn);
    }
}

void split(Treap *t, Treap *&a, Treap *&b, int k)
{
    if(t == NULL)
    {
        a = b = NULL;
        return;
    }
    t->push();
    if(getSize(t->lc) < k)
    {
        a = t;
        split(t->rc, a->rc, b, k - getSize(t->lc) - 1);
        a->pull();
    }
    else
    {
        b = t;
        split(t->lc, a, b->lc, k);
        b->pull();
    }
}

Treap* merge(Treap *a, Treap *b)
{
    if(!a || !b)
    {
        return (a ? a : b);
    }
    if(a->pri > b->pri)
    {
        a->push();
        a->rc = merge(a->rc, b);
        a->pull();
        return a;
    }
    else
    {
        b->push();
        b->lc = merge(a, b->lc);
        b->pull();
        return b;
    }
}

void addVal(Treap *&t, int x, int y, int d)
{
    Treap *a, *b, *c;
    split(t, b, c, y);
    split(b, a, b, x - 1);
    b->val += d;
    b->add += d;
    b->mn += d;
    t = merge(a, merge(b, c));
}

void revolve(Treap *&t, int x, int y, int T)
{
    int len = y - x + 1;
    T %= len;
    Treap *a, *b, *c, *d, *e;
    split(t, b, c, y);
    split(b, a, b, x - 1);
    split(b, d, e, len - T);
    t = merge(a, merge(e, merge(d, c)));
}

void Reverse(Treap *&t, int x, int y)
{
    Treap *a, *b, *c;
    split(t, b, c, y);
    split(b, a, b, x - 1);
    b->rev = !b->rev;
    swap(b->lc, b->rc);
    t = merge(a, merge(b, c));
}

void Insert(Treap *&t, int x, int p)
{
    Treap *a, *b;
    split(t, a, b, x);
    t = merge(a, merge(new Treap(p), b));
}

void Delete(Treap *&t, int x)
{
    Treap *a, *b, *c;
    split(t, b, c, x);
    split(b, a, b, x - 1);
    t = merge(a, c);
}

int getMin(Treap *&t, int x, int y)
{
    Treap *a, *b, *c;
    split(t, b, c, y);
    split(b, a, b, x - 1); 
    int res = b->mn;
    t = merge(a, merge(b, c));
    return res;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int n, q;
    string s;
    Treap *root = NULL;

    cin >> n;
    for(int i = 0, val; i != n; ++i)
    {
        cin >> val;
        root = merge(root, new Treap(val));
    }

    cin >> q;
    for(int i = 0, x, y, z; i != q; ++i)
    {
        // cout << '*' << i << '\n';
        // dfs(root); cout << '\n';
        cin >> s;
        if(s == "ADD")
        {
            cin >> x >> y >> z;
            addVal(root, x, y, z);
        }
        else if(s == "REVERSE")
        {
            cin >> x >> y;
            Reverse(root, x, y);
        }
        else if(s == "REVOLVE")
        {
            cin >> x >> y >> z;
            revolve(root, x, y, z);
        }
        else if(s == "INSERT")
        {
            cin >> x >> y;
            Insert(root, x, y);
        }
        else if(s == "DELETE")
        {
            cin >> x;
            Delete(root, x);
        }
        else if(s == "MIN")
        {
            cin >> x >> y;
            cout << getMin(root, x, y) << '\n';
        }
    }
}