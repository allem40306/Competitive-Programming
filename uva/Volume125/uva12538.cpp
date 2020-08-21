#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 3e7;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
struct Node
{
    static Node mem[MXN];
    Node *Lc, *Rc;
    char ch;
    int sz;
    Node() {}
    Node(char _ch) : Lc(nullptr), Rc(nullptr), ch(_ch), sz(1) {}
} Node::mem[MXN], *ptr = Node::mem;

inline int sz(Node *a) { return a ? a->sz : 0; }

inline void pull(Node *a)
{
    if (!a)
    {
        return;
    }
    a->sz = 1 + sz(a->Lc) + sz(a->Rc);
}

void split(Node *t, Node *&a, Node *&b, int k)
{
    if (t == NULL)
    {
        a = b = NULL;
        return;
    }
    if (sz(t->Lc) + 1 <= k)
    {
        a = new (ptr++) Node(*t);
        split(t->Rc, a->Rc, b, k - 1 - sz(t->Lc));
        pull(a);
    }
    else
    {
        b = new (ptr++) Node(*t);
        split(t->Lc, a, b->Lc, k);
        pull(b);
    }
}

Node *merge(Node *a, Node *b)
{
    if (!a || !b)
    {
        return (a ? a : b);
    }
    Node *res;
    if (rand() % (sz(a) + sz(b)) < sz(a))
    {
        res = new (ptr++) Node(*a);
        res->Rc = merge(a->Rc, b);
    }
    else
    {
        res = new (ptr++) Node(*b);
        res->Lc = merge(a, b->Lc);
    }
    pull(res);
    return res;
}

int n;
Node *ver[MXN];
string s;
int d;

void print(Node *t)
{
    if (!t)
    {
        return;
    }
    print(t->Lc);
    cout << t->ch;
    if (t->ch == 'c')
    {
        ++d;
    }
    print(t->Rc);
}

int main()
{
    // IOS;
    cin >> n;
    int vi = 0;
    FOR(i, 0, n)
    {
        Node *Lt, *Mt, *Rt;
        int x;
        cin >> x;
        if (x == 1)
        {
            ++vi;
            ver[vi] = ver[vi - 1];
            int p;
            cin >> p >> s;
            p -= d;
            split(ver[vi], Lt, Rt, p);
            FOR(i, 0, s.size()) { Lt = merge(Lt, new (ptr++) Node(s[i])); }
            ver[vi] = merge(Lt, Rt);
        }
        else if (x == 2)
        {
            ++vi;
            ver[vi] = ver[vi - 1];
            int p, c;
            cin >> p >> c;
            p -= d;
            c -= d;
            split(ver[vi], Lt, Rt, p - 1);
            split(Rt, Mt, Rt, c);
            ver[vi] = merge(Lt, Rt);
        }
        else
        {
            int v, p, c;
            cin >> v >> p >> c;
            v -= d;
            p -= d;
            c -= d;
            split(ver[v], Lt, Rt, p - 1);
            split(Rt, Mt, Rt, c);
            print(Mt);
            cout << '\n';
        }
    }
}
