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
const int MXN = 0;
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
    int val;
    Node *Lc, *Rc;
    Node() : Lc(nullptr), Rc(nullptr) {}
};

Node *insert(Node *node, int val)
{
    if (node == nullptr)
    {
        node = new Node();
        node->val = val;
    }
    else if (val < node->val)
    {
        node->Lc = insert(node->Lc, val);
    }
    else
    {
        node->Rc = insert(node->Rc, val);
    }
    return node;
}

bool first;
void dfs(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    if (!first)
    {
        cout << ' ';
    }
    first = false;
    cout << node->val;
    dfs(node->Lc);
    dfs(node->Rc);
}

int main()
{
    IOS;
    int n, x;
    while (cin >> n)
    {
        Node *root = nullptr;
        FOR(i, 0, n)
        {
            cin >> x;
            root = insert(root, x);
        }
        first = true;
        dfs(root);
        cout << '\n';
    }
}
