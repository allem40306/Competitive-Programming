#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9;

struct Mat
{
    long long v[2][2];
    Mat() { memset(v, 0, sizeof(v)); }
};

Mat mul(Mat &a, Mat &b)
{
    Mat c;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c.v[i][j] = (c.v[i][j] + a.v[i][k] * b.v[k][j]) % mod;
    return c;
}

long long fPow(int n)
{
    Mat ans, tmp;
    ans.v[0][0] = 1;
    ans.v[1][0] = 0;
    tmp.v[0][0] = 1;
    tmp.v[0][1] = 1;
    tmp.v[1][0] = 1;
    tmp.v[1][1] = 0;
    for (; n > 0; n >>= 1)
    {
        if (n & 1)
            ans = mul(ans, tmp);
        tmp = mul(tmp, tmp);
    }
    return ans.v[0][0] % mod;
}

int main()
{
    long long n, m;
    while (cin >> n >> m)
    {
        mod = (1 << m);
        if (n == 0)
            cout << 0 << '\n';
        else
            cout << fPow(n - 1) << '\n';
    }
}
