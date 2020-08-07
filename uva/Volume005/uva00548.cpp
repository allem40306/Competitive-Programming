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
vector<int> inorder, postorder;
vector<int> L, R;

bool input(vector<int> &v)
{
    string s;
    if (!getline(cin, s))
    {
        return false;
    }
    stringstream ss(s);
    v.clear();
    int x;
    while (ss >> x)
    {
        v.push_back(x);
    }
    return true;
}

int ansp, ansv;
void dfs(int L1, int R1, int L2, int R2, int sum)
{
    // cout << L1 << ' ' << R1 << ' ' << L2 << ' ' << R2 << ' ' << sum << '\n';
    int root1 = 0, root2 = R2 - 1;
    sum += postorder[root2];
    if (L1 + 1 > R1 || L2 + 1 > R2)
    {
        return;
    }
    if (L1 + 1 == R1 && L2 + 1 == R2)
    {
        if (sum <= ansv || (sum == ansv && postorder[root2 - 1] < ansv))
        {
            ansv = sum;
            ansp = postorder[root2];
        }
        return;
    }
    FOR(i, L1, R1) if (inorder[i] == postorder[root2])
    {
        root1 = i;
        break;
    }
    dfs(L1, root1, L2, L2 + (root1 - L1), sum);
    dfs(root1 + 1, R1, L2 + (root1 - L1), R2 - 1, sum);
}

int main()
{
    IOS;
    while (input(inorder))
    {
        input(postorder);
        L.resize(inorder.size());
        R.resize(inorder.size());
        ansp = ansv = INF;
        dfs(0, (int)inorder.size(), 0, (int)inorder.size(), 0);
        cout << ansp << '\n';
    }
}
