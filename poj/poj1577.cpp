#pragma GCC optimize(2)
#include <cstring>
#include <iostream>
#include <stack>
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
struct Node
{
    char val;
    Node *Lc, *Rc;
    Node() : Lc(NULL), Rc(NULL) {}
};

Node *insert(Node *node, char val)
{
    if (node == NULL)
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

void dfs(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->val;
    dfs(node->Lc);
    dfs(node->Rc);
}

int main()
{
    IOS;
    string s;
    stack<string> st;
    while (cin >> s)
    {
        do
        {
            st.push(s);
        } while (cin >> s, isalpha(s[0]));
        Node *root = NULL;
        while (!st.empty())
        {
            s = st.top();
            st.pop();
            FOR(i, 0, s.size()) { root = insert(root, s[i]); }
        }
        dfs(root);
        cout << '\n';
    }
}