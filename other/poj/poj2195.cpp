#pragma GCC optimize(2)
#include <bitset>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e6 + 5;
const int MXV = 1e2 + 5;
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
template <typename T>

struct KM
{
    int n;
    int Left[MXV];
    T w[MXV][MXV], Lx[MXV], Ly[MXV];
    bitset<MXV> vx, vy;

    void init(int _n)
    {
        n = _n;
        memset(w, 0, sizeof(w));
    }

    bool match(int i)
    {
        vx[i] = true;
        for (int j = 1; j <= n; j++)
        {
            if ((abs(Lx[i] + Ly[j] - w[i][j]) < 1e-9) && !vy[j])
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
                for (int j = 1; j <= n; j++)
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
            if (vy[i])
            {
                Ly[i] += a;
            }
        }
    }

    void hungarian()
    {
        memset(Ly, 0, sizeof(Ly));
        memset(Left, 0, sizeof(Left));
        for (int i = 1; i <= n; i++)
        {
            Lx[i] = w[i][1];
            for (int j = 1; j <= n; j++)
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
        FOR(i, 1, n + 1) { ans += Lx[i] + Ly[i]; }
        printf("%d\n", -ans);
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
    int n, m;
    vector<PII> v, w;
    while (scanf("%d %d", &n, &m), n || m)
    {
        char ch;
        v.clear();
        w.clear();
        FOR(i, 1, n + 1) FOR(j, 1, m + 1)
        {
            scanf(" %c", &ch);
            if (ch == 'm')
            {
                v.push_back(make_pair(i, j));
            }
            if (ch == 'H')
            {
                w.push_back(make_pair(i, j));
            }
        }
        km.init((int)v.size());
        FOR(i, 0, v.size()) FOR(j, 0, w.size())
        {
            km.w[i + 1][j + 1] = -(abs(v[i].F - w[j].F) + abs(v[i].S - w[j].S));
        }
        km.hungarian();
    }
}