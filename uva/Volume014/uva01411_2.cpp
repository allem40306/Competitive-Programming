#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 105;
#define MP make_pair

template <typename T>
struct KM
{
    int n;
    int Left[N];
    T w[N][N], Lx[N], Ly[N];
    bitset<N> vx, vy;
    
    void init(int _n)
    {
        n = _n;
    }

    bool match(int i)
    {
        vx[i] = true;
        for (int j = 1; j <= n; j++)
        {
            if ((fabs(Lx[i] + Ly[j] - w[i][j]) < 1e-9) && !vy[j])
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
        T a = 1e30;
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
        for (int i = 1; i <= n; i++)
        {
            Left[i] = Lx[i] = Ly[i] = 0;
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
    }
};

int main()
{
    int n;
    bool f = 0;
    vector<PII> setA, setB;
    KM<double> km;
    while (cin >> n)
    {
        km.init(n);
        setA.resize(n + 5);
        setB.resize(n + 5);
        for (int i = 1, x, y; i <= n; i++)
        {
            cin >> x >> y;
            setA[i] = MP(x, y);
        }
        for (int i = 1, x, y; i <= n; i++)
        {
            cin >> x >> y;
            setB[i] = MP(x, y);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                km.w[j][i] = -sqrt((double)(setA[i].first - setB[j].first) *
                                    (setA[i].first - setB[j].first) +
                                (double)(setA[i].second - setB[j].second) *
                                    (setA[i].second - setB[j].second));
            }
        }
        km.hungarian();
        if (f)
        {
            cout << '\n';
        }
        f = true;
        for (int i = 1; i <= n; i++)
        {
            cout << km.Left[i] << '\n';
        }
    }
}