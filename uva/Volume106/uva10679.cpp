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
const int MXN = 0;
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

// void build_fail_function(string B, int *fail)
// {
//     int len = B.size(), current_pos;
//     current_pos = fail[0] = -1;
//     for (int i = 1; i < len; ++i)
//     {
//         while (current_pos != -1 && B[current_pos + 1] != B[i])
//         {
//             current_pos = fail[current_pos];
//         }

//     }
// }

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        string s, r;
        int n;
        cin >> s >> n;
        while (n--)
        {
            cin >> r;
            int ok = 0;
            for (int i = 0; i + (int)r.size() - 1 < (int)s.size(); ++i)
            {
                // cout << s.substr(i, r.size()) << '\n';
                if (s.substr(i, r.size()) == r)
                    ok = 1;
            }
            cout << "ny"[ok] << '\n';
        }
    }
}
