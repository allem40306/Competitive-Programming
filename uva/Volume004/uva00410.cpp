#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 5;
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

int main()
{
    IOS;
    int c, s, ti = 0;
    vector<double> a(10);
    while (cin >> c >> s)
    {
        double sum = 0, avg = 0, ans = 0;
        fill(a.begin(), a.end(), 0);
        FOR(i, 0, s)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end(), greater<double>());
        avg = sum / (double)c;
        cout << "Set #" << ++ti << '\n';
        FOR(i, 0, c)
        {
            int j = 2 * c - i - 1;
            cout << setw(2) << i << ':';
            if (a[i])
            {
                cout << fixed << setprecision(0) << ' ' << a[i];
            }
            if (a[j])
            {
                cout << fixed << setprecision(0) << ' ' << a[j];
            }
            cout << '\n';
            ans += abs((a[i] + a[j]) - avg);
        }
        cout << fixed << setprecision(5) << "IMBALANCE = " << ans << "\n\n";
    }
}
