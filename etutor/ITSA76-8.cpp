#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
vector<int> square(16, 0);
int cnt = 0;
vector<int> check = {-4, -3, 4, 5};
bool ok;

void dfs(int id)
{
    // cout << cnt << '\n';
    // FOR(i, 0, 16) { cout << square[i] << " \n"[i % 4 == 3]; }
    if (id == 16)
    {
        if (cnt == 16)
        {
            ok = true;
        }
        return;
    }
    dfs(id + 1);
    if (square[id] != 0 || id % 4 == 3 || square[id + 1] != 0)
    {
        return;
    }
    square[id] = square[id + 1] = 1;
    FOR(i, 0, check.size())
    {
        if (0 <= id + check[i] && id + check[i] < 16 &&
            square[id + check[i]] == 0)
        {
            square[id + check[i]] = 1;
            cnt += 3;
            dfs(id + 1);
            cnt -= 3;
            square[id + check[i]] = 0;
        }
    }
    square[id] = square[id + 1] = 0;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    FOR(ti, 0, t)
    {
        cnt = 0;
        FOR(i, 0, 16)
        {
            cin >> square[i];
            if (square[i] == 1)
            {
                ++cnt;
            }
        }
        ok = false;
        dfs(0);
        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
