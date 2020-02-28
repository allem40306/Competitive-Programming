#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using LD = long double;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 1 << 20;
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

bitset<MXN> is_notp;
vector<int> p;

void primeTable()
{
    is_notp.reset();
    is_notp[0] = is_notp[1] = 1;
    for (int i = 2; i < MXN; i++)
    {
        if (!is_notp[i])
        {
            p.push_back(i);
        }
        for (int j = 0; j < (int)p.size() && i * p[j] < MXN; j++)
        {
            is_notp[i * p[j]] = 1;
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
}

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
    void fft(vector<Complex> &a, int n, int inv)
    {
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
    void convolution(vector<Complex> &A, vector<Complex> &B, vector<Complex> &C,
                     vector<Complex> &D, int n, vector<Complex> &ans)
    {
        fft(A, n, 1);
        fft(B, n, 1);
        fft(C, n, 1);
        fft(D, n, 1);
        FOR(i, 0, n) { ans[i] = A[i] * B[i] * C[i] * D[i]; }
        fft(ans, n, -1);
        return;
    }
};

int main()
{
    IOS;
    int a, b, c;
    FFT<LD> fft;
    vector<Complex> A(MXN), B(MXN), C(MXN), D(MXN), ans(MXN);
    primeTable();
    while (cin >> a >> b >> c, a || b || c)
    {
        int sz = 1;
        while (sz < (b << 1))
        {
            sz <<= 1;
        }
        sz <<= 1;
        FOR(i, 0, sz) 
        { 
            A[i].r = B[i].r = C[i].r = D[i].r = 0.0;
            A[i].i = B[i].i = C[i].i = D[i].i = 0.0; 
        }
        FOR(i, 2, b + 1)
        {
            if (is_notp[i])
            {
                A[i].r = B[i].r = C[i].r = D[i].r = 1.0;;
            }
        }
        int val;
        string s;
        FOR(i, 0, c)
        {
            val = 0;
            cin >> s;
            FOR(i, 0, s.size() - 1) { val = val * 10 + (s[i] - '0'); }
            switch (s[s.size() - 1])
            {
            case 'S':
                A[val].r = 0.0;
                break;
            case 'H':
                B[val].r = 0.0;
                break;
            case 'C':
                C[val].r = 0.0;
                break;
            case 'D':
                D[val].r = 0.0;
                break;
            }
        }
        fft.convolution(A, B, C, D, sz, ans);
        FOR(i, a, b + 1) { cout << LL(ans[i].r + 0.5) << '\n'; }
        cout << '\n';
    }
}
