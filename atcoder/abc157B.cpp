/*
source: ABC 157 B Bingo
*/
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

int main()
{
    IOS;
    map<int, int> tb;
    bitset<3> bingo[3];
    FOR(i, 0, 3) { bingo[i].reset(); }
    int n;
    int x;
    FOR(i, 0, 9)
    {
        cin >> x;
        tb.insert({x, i});
    }
    cin >> n;
    FOR(i, 0, n)
    {
        cin >> x;
        if (tb.find(x) == tb.end())
        {
            continue;
        }
        int res = tb[x];
        int a = res / 3, b = res % 3;
        bingo[a][b] = true;
    }
    bool ok = false;
    if(bingo[0][0] && bingo[1][1] && bingo[2][2])
    {
        ok = true;
    }
    if(bingo[0][2] && bingo[1][1] && bingo[2][0])
    {
        ok = true;
    }
    FOR(i, 0, 3)
    {
        if(bingo[0][i] && bingo[1][i] && bingo[2][i])
        {
            ok = true;
        }
        if(bingo[i][0] && bingo[i][1] && bingo[i][2])
        {
            ok = true;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
}
