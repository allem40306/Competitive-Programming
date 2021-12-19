#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MXV = 3e5 + 5;
const ULL MOD = 10009;
const ULL seed = 31;
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

string s;
int si;
int ans1, ans2;

bool hasNext()
{
    if (si == (int)s.size())
    {
        return false;
    }
    ++si;
    return true;
}

void dfs(int preD, int postD)
{
    int tmp = 0;
    // cout << preD << ' ' << postD << '\n';
    ans1 = max(ans1, preD);
    ans2 = max(ans2, postD);
    while (hasNext())
    {
        if (s[si] == 'd')
        {
            ++tmp;
            dfs(preD + 1, postD + tmp);
        }
        else
        {
            return;
        }
    }
}

int main()
{
    int ti = 0;
    while (cin >> s, s != "#")
    {
        cout << "Tree " << ++ti << ": ";
        ans1 = ans2 = 0;
        si = -1;
        dfs(0, 0);
        cout << ans1 << " => " << ans2 << '\n';
    }
}