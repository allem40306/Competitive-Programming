#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = (1 << 23);
const int MXV = 0;
const LD PI = acos(-1.0);
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

struct Complex
{
    LD r, i;
    Complex(LD _r = 0.0, LD _i = 0.0)
    {
        r = _r;
        i = _i;
    }
    Complex operator+(Complex rhs) { return Complex(r + rhs.r, i + rhs.i); }
    Complex operator-(Complex rhs) { return Complex(r - rhs.r, i - rhs.i); }
    Complex operator*(Complex rhs)
    {
        return Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r);
    }
};

template <typename T> struct FFT
{
    void fft(vector<Complex> &a, int inv)
    {
        int n = (int)a.size();
        for (int i = 1, j = 0; i < n; ++i)
        {
            for (int k = (n >> 1); (j ^= k) < k; k >>= 1)
                ;
            if (i > j)
            {
                swap(a[i], a[j]);
            }
        }
        for (int m = 2; m <= n; m <<= 1)
        {
            Complex wm(cos(2 * PI * inv / m), sin(2 * PI * inv / m));
            for (int k = 0; k < n; k += m)
            {
                Complex w(1.0, 0.0);
                for (int j = 0; j < (m >> 1); ++j, w = w * wm)
                {
                    Complex u = a[k + j], t = w * a[k + j + (m >> 1)];
                    a[k + j] = u + t;
                    a[k + j + (m >> 1)] = u - t;
                }
            }
        }
        if (inv == -1)
        {
            FOR(i, 0, n)
            {
                a[i].r /= n;
                a[i].i /= n;
            }
        }
    }
    void convolution(vector<Complex> &A, vector<Complex> &B, int n,
                     vector<Complex> &C)
    {
        fft(A, 1);
        fft(B, 1);
        FOR(i, 0, n) { C[i] = A[i] * B[i]; }
        fft(C, -1);
        return;
    }
};

int main()
{
    // IOS;
    int sz = 1;
    while (sz < (MXN << 1))
    {
        sz <<= 1;
    }
    sz <<= 1;
    FFT<LD> fft;
    vector<Complex> a(sz), b(sz), c(sz);
    vector<int> times(MXN, 0);
    vector<LL> res(sz, 0);
    FOR(i, 1, MXN)
    {
        for (int j = i; j < MXN; j += i)
        {
            ++times[j];
        }
    }
    FOR(i, 0, sz)
    {
        a[i].r = b[i].r = a[i].i = b[i].i = 0;
    }
    FOR(i, 0, MXN)
    {
        a[i].r = b[i].r = times[i];
    }
    fft.convolution(a, b, a.size(), c);

    FOR(i, 0, sz) { res[i] = LL(c[i].r + 0.5); }

    int t, L, R;
    cin >> t;
    while (t--)
    {
        cin >> L >> R;
        int ans = L;
        FOR(i, L, R + 1)
        {
            if (res[i] > res[ans])
            {
                ans = i;
            }
        }
        cout << ans << ' ' << res[ans] << '\n';
    }
}
