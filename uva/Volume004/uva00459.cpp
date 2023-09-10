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
const int MXV = 30;
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

int p[MXV], sz[MXV];
void init()
{
    for (int i = 0; i < MXV; ++i)
    {
        p[i] = i;
        sz[i] = 1;
    }
}

int Find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = Find(p[x]);
}

bool Union(int x, int y)
{
    if (x == y)
        return false;
    if (sz[x] > sz[y])
        swap(x, y);
    p[x] = y;
    sz[y] += sz[x];
    return true;
}

int main()
{
    IOS;
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti)
    {
        char a, b;
        cin >> a;
        int v = a - 'A' + 1, x, y;
        init();

        string s;
        getline(cin, s);
        while (getline(cin, s), s != "")
        {
            stringstream ss(s);
            ss >> a >> b;
            x = a - 'A';
            y = b - 'A';
            if(Union(Find(x), Find(y)))--v;
        }
        if (ti)
            cout << '\n';
        cout << v << '\n';
    }
}
