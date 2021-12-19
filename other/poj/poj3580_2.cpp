#pragma GCC optimize(2)
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long LL;
const LL INF = (1 << 29);
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
struct Node
{
    Node *ch[2];
    LL val, sz;
    LL add, mn;
    bool rev;
    Node()
    {
        sz = add = 0;
        rev = false;
        mn = INF;
    }
    void maintain();
    void push();
    int cmp(int x);
};
int getSize(Node *T) { return (T ? T->sz : 0); }
LL getMn(Node *T) { return (T ? T->mn : INF); }

void Node::maintain()
{
    sz = getSize(ch[0]) + getSize(ch[1]) + 1;
    mn = min(val, min(getMn(ch[0]), getMn(ch[1])));
}
void Node::push()
{
    if (rev)
    {
        rev = 0;
        swap(ch[0], ch[1]);
        FOR(i, 0, 2) if (ch[i]) { ch[i]->rev = !ch[i]->rev; }
    }
    if (add)
    {
        FOR(i, 0, 2) if (ch[i])
        {
            ch[i]->val += add;
            ch[i]->add += add;
            ch[i]->mn += add;
        }
        add = 0;
    }
}
int Node::cmp(int x)
{
    int d = x - getSize(ch[0]);
    if (d == 1)
    {
        return -1;
    }
    return (d <= 0 ? 0 : 1);
}

Node *null = new Node();
Node *root;
Node *a, *b, *c, *d, *e;
LL arr[200005];

void Rotate(Node *&T, int dir)
{
    Node *tmp = T->ch[dir ^ 1];
    T->ch[dir ^ 1] = tmp->ch[dir];
    tmp->ch[dir] = T;
    T->maintain();
    tmp->maintain();
    T = tmp;
}

void splay(Node *&T, int k)
{
    T->push();
    int dir = T->cmp(k);
    if (dir == 1)
    {
        k -= getSize(T->ch[0]) + 1;
    }
    if (dir != -1)
    {
        Node *tmp = T->ch[dir];
        tmp->push();
        int dir2 = tmp->cmp(k);
        if (dir2 != -1)
        {
            int k2 = (dir2 == 0 ? k : k - getSize(tmp->ch[0]) - 1);
            splay(tmp->ch[dir2], k2);
            if (dir == dir2)
            {
                Rotate(T, dir ^ 1);
            }
            else
            {
                Rotate(T->ch[dir], dir);
            }
        }
        Rotate(T, dir ^ 1);
    }
}

Node *merge(Node *L, Node *R)
{
    // cout << getSize(L) << ' ' << getSize(R) << '\n';
    if (!getSize(L))
    {
        return R;
    }
    splay(L, getSize(L));
    L->ch[1] = R;
    L->maintain();
    return L;
}

void split(Node *T, int k, Node *&L, Node *&R)
{
    splay(T, k);
    L = T;
    R = T->ch[1];
    T->ch[1] = NULL;
    L->maintain();
}

void build(Node *&T, int L, int R)
{
    if (L > R)
    {
        return;
    }
    int M = (L + R) >> 1;
    T = new Node();
    T->val = T->mn = arr[M];
    T->sz = 1;
    T->ch[0] = T->ch[1] = NULL;
    build(T->ch[0], L, M - 1);
    build(T->ch[1], M + 1, R);
    T->maintain();
}

void insert(int x, int v)
{
    split(root, x + 1, a, b);
    Node *node = new Node();
    node->val = node->mn = v;
    node->sz = 1;
    node->ch[0] = node->ch[1] = NULL;
    root = merge(merge(a, node), b);
}

void Delete(int x)
{
    split(root, x, a, b);
    split(b, 1, c, d);
    root = merge(a, d);
}

void getMin(int x, int y)
{
    split(root, x, a, b);
    split(b, y - x + 1, c, d);
    cout << c->mn << '\n';
    root = merge(merge(a, c), d);
}

void revolve(int x, int y, int z)
{
    split(root, x, a, b);
    split(b, y - x + 1, c, d);
    split(c, y - x + 1 - z, e, b);
    root = merge(merge(a, merge(b, e)), d);
}

void add(int x, int y, int z)
{
    split(root, x, a, b);
    split(b, y - x + 1, c, d);
    c->val += z;
    c->add += z;
    c->mn += z;
    root = merge(merge(a, c), d);
}

void reverse(int x, int y)
{
    split(root, x, a, b);
    split(b, y - x + 1, c, d);
    c->rev = !c->rev;
    root = merge(merge(a, c), d);
}

int main()
{
    IOS;
    int n, q;
    string s;

    cin >> n;
    arr[0] = INF;
    FOR(i, 1, n + 1) { cin >> arr[i]; }
    build(root, 0, n);
    cin >> q;
    for (int i = 0, x, y, z; i != q; ++i)
    {
        // cout << '*' << i << '\n';
        // dfs(root); cout << '\n';
        cin >> s;
        // cout << i << ' ' << s << ' ' << getSize(root) << '\n';
        if (s == "ADD")
        {
            cin >> x >> y >> z;
            add(x, y, z);
        }
        else if (s == "REVERSE")
        {
            cin >> x >> y;
            reverse(x, y);
        }
        else if (s == "REVOLVE")
        {
            cin >> x >> y >> z;
            revolve(x, y, (z % (y - x + 1) + (y - x + 1)) % (y - x + 1));
        }
        else if (s == "INSERT")
        {
            cin >> x >> y;
            insert(x, y);
        }
        else if (s == "DELETE")
        {
            cin >> x;
            Delete(x);
        }
        else if (s == "MIN")
        {
            cin >> x >> y;
            getMin(x, y);
        }
    }
}