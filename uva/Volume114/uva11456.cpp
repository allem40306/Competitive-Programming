#include <algorithm>
#include <iostream>

using namespace std;
#define MXN 2005
void init(int a[])
{
    for (int i = 0; i < MXN; i++)
        a[i] = 1;
}

int main()
{
    int tc, ti = 0, n, lis[MXN], lis2[MXN], maxx, m[MXN];
    for (cin >> tc; ti < tc; ti++)
    {
        cin >> n;
        maxx = 0;
        for (int i = 0; i < n; i++)
            cin >> m[i];
        init(lis);
        init(lis2);
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
            {
                if (m[i] < m[j])
                    lis[i] = max(lis[i], lis[j] + 1);
                if (m[i] > m[j])
                    lis2[i] = max(lis2[i], lis2[j] + 1);
            }
        for (int i = 0; i < n; i++)
            maxx = max(maxx, lis[i] + lis2[i] - 1);
        printf("%d\n", maxx);
    }
}