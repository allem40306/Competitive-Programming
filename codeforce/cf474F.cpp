#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
vector<int> v;
struct Node{
    int gcd, cnt;
    Node *lc, *rc;
    Node(): gcd(0), cnt(0), lc(nullptr), rc(nullptr){};
    void pull()
    {
        gcd = __gcd(lc->gcd, rc->gcd);
        if(lc->gcd == gcd)
        {
            cnt += lc->cnt;
        }
        if(rc->gcd == gcd)
        {
            cnt += rc->cnt;
        }
    }
};

Node *build(int L, int R)
{
    Node *node = new Node();
    if(L == R)
    {
        node->gcd = v[L];
        node->cnt = 1;
        return node;
    }
    int M = (L + R) >> 1;
    node->lc = build(L, M);
    node->rc = build(M + 1, R);
    node->pull();
    return node;
}

PII query(Node *node, int L, int R, int qL, int qR)
{
    if(qL <= L && R <= qR)
    {
        return {node->gcd, node->cnt};
    }
    int M = (L + R) >> 1;
    if(qR <= M)
    {
        return query(node->lc, L, M, qL, qR);
    }
    else if (M < qL)
    {
        return query(node->rc, M + 1, R, qL, qR);
    }
    else
    {
        auto lhs = query(node->lc, L, M, qL, qR);
        auto rhs = query(node->rc, M + 1, R, qL, qR);
        int gcd = __gcd(lhs.first, rhs.first), cnt = 0;
        if(lhs.first == gcd)
        {
            cnt += lhs.second;
        }
        if(rhs.first == gcd)
        {
            cnt += rhs.second;
        }
        return {gcd, cnt};
    }
}

int main()
{
    int n, q;
    cin >> n;
    v.resize(n + 5);
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }
    Node *root = build(1, n);
    cin >> q;
    for(int i = 0, x, y; i != q; ++i)
    {
        cin >> x >> y;
        cout << y - x + 1 - query(root, 1, n, x, y).second << '\n';
    }
}