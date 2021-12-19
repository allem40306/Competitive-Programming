#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e6 + 5;
const int MXV = 2e2 + 5;
typedef pair<int, int> PII;
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

int Left[MXV];
int w[MXV][MXV], Lx[MXV], Ly[MXV];
bitset<MXV> vx;
bitset<MXV> vy;

template <typename T>

struct KM
{
    int n, m;
    void init(int _n, int _m)
    {
        n = _n;
        m = _m;
        memset(w, 0, sizeof(w));
    }

    bool match(int i)
    {
        vx[i] = true;
        for (int j = 1; j <= m; j++)
        {
            if ((Lx[i] + Ly[j] == w[i][j]) && !vy[j])
            {
                vy[j] = 1;
                if (!Left[j] || match(Left[j]))
                {
                    Left[j] = i;
                    return true;
                }
            }
        }
        return false;
    }

    void update()
    {
        T a = 1e9;
        for (int i = 1; i <= n; i++)
        {
            if (vx[i])
            {
                for (int j = 1; j <= m; j++)
                {
                    if (!vy[j])
                    {
                        a = min(a, Lx[i] + Ly[j] - w[i][j]);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vx[i])
            {
                Lx[i] -= a;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (vy[i])
            {
                Ly[i] += a;
            }
        }
    }

    int hungarian()
    {
        memset(Ly, 0, sizeof(Ly));
        memset(Left, 0, sizeof(Left));
        for (int i = 1; i <= n; i++)
        {
            Lx[i] = w[i][1];
            for (int j = 1; j <= m; j++)
            {
                Lx[i] = max(Lx[i], w[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            while (1)
            {
                vx.reset();
                vy.reset();
                if (match(i))
                {
                    break;
                }
                update();
            }
        }
        int ans = 0;
        FOR(i, 1, m + 1) if (Left[i]) ans += w[Left[i]][i];
        return ans;
    }
};

/*
usage
KM<int> km; // declare with weight type
km.init(n); // initialize with vertex
km.hungarian(); // calculate
km.w[][]; // weight array
km.Left[i] // y_i match x_Left[i]
*/

int main()
{
    KM<int> km;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        km.init(n, n);
        int tot = 0;
        FOR(i, 1, n + 1) FOR(j, 1, n + 1)
        {
            scanf("%d", &w[i][j]);
            tot += w[i][j];
            w[i][j] = w[i][j];
        }
        printf("%d\n", tot - km.hungarian());
    }
}