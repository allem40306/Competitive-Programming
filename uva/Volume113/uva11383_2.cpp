#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
const int N = 505;

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
    IOS;
    int n;
    KM<int> km;
    while(cin >> n)
    {
        km.init(n);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> km.w[i][j];
            }
        }
        km.hungarian();
        for(int i = 1; i <= n; ++i)
        {
            cout << km.Lx[i] << " \n"[i == n];
        }
        for(int i = 1; i <= n; ++i)
        {
            cout << km.Ly[i] << " \n"[i == n];
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            ans += km.w[km.Left[i]][i];
        }
        cout << ans << '\n';
    }
}
