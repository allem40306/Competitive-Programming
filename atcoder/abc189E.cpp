#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 2e5 + 5;
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
struct Matrix
{
    LL v[3][3];
    Matrix() { memset(v, 0, sizeof(v)); }
    void output()
    {
        FOR(i, 0, 3) FOR(j, 0, 3) cout << v[i][j] << " \n"[j == 2];
        cout << '\n';
    }
};

Matrix mul(Matrix &a, Matrix &b)
{
    Matrix c;
    FOR(i, 0, 3) FOR(j, 0, 3) FOR(k, 0, 3) c.v[i][j] += a.v[i][k] * b.v[k][j];
    return c;
}
Matrix a[MXN], b[MXN], op[5];

void init()
{
    b[0].v[0][0] = b[0].v[1][1] = b[0].v[2][2] = 1;
    op[1].v[0][1] = op[1].v[2][2] = 1, op[1].v[1][0] = -1;
    op[2].v[1][0] = op[2].v[2][2] = 1, op[2].v[0][1] = -1;
    op[3].v[1][1] = op[3].v[2][2] = 1, op[3].v[0][0] = -1;
    op[4].v[0][0] = op[4].v[2][2] = 1, op[4].v[1][1] = -1;
}

int main()
{
    IOS;
    int n, m, q, x, y;
    init();
    cin >> n;
    FOR(i, 1, n + 1)
    {
        cin >> a[i].v[0][0] >> a[i].v[1][0];
        a[i].v[2][0] = 1;
    }
    cin >> m;
    FOR(i, 1, m + 1)
    {
        cin >> x;
        if (x > 2)
            cin >> y;
        if (x == 3)
            op[3].v[0][2] = 2 * y;
        if (x == 4)
            op[4].v[1][2] = 2 * y;
        b[i] = mul(op[x], b[i - 1]);
    }
    Matrix ans;
    cin >> q;
    FOR(i, 0, q)
    {
        cin >> x >> y;
        ans = mul(b[x], a[y]);
        cout << ans.v[0][0] << ' ' << ans.v[1][0] << '\n';
    }
}
