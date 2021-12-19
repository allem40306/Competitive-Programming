#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MXV = 3e5 + 5;
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

string preorder, inorder;
void dfs(int L1, int R1, int L2, int R2)
{
    // cout << L1 << ' ' << R1 << ' ' << L2 << ' ' << R2 << '\n';
    int root1 = L1, root2 = 0;
    if (L1 + 1 > R1 || L2 + 1 > R2)
    {
        return;
    }
    if (L1 + 1 == R1 && L2 + 1 == R2)
    {
        cout << preorder[L1];
        return;
    }
    FOR(i, L2, R2) if (preorder[root1] == inorder[i])
    {
        root2 = i;
        break;
    }
    dfs(L1 + 1, L1 + 1 + (root2 - L2), L2, root2);
    dfs(L1 + 1 + (root2 - L2), R1, root2 + 1, R2);
    cout << preorder[root1];
}

int main()
{
    IOS;
    while (cin >> preorder >> inorder)
    {
        dfs(0, (int)inorder.size(), 0, (int)inorder.size());
        cout << '\n';
    }
}