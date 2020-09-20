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
const int MXN = 1e2 + 5;
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
int cnt[MXN][3], mx[3];
string name[MXN];
string message[3] = {
    "If you want to call a taxi, you should call:",
    "If you want to order a pizza, you should call:",
    "If you want to go to a cafe with a wonderful girl, you should call:"};

bool isTaxi(const string &s)
{
    FOR(i, 0, s.size()) if (s[i] >= '0' && s[i] <= '9' && s[i] != s[0])
    {
        return false;
    }
    return true;
}

bool isPizza(const string &s)
{
    int pos = 0;
    FOR(i, 1, s.size()) if (s[i] >= '0' && s[i] <= '9')
    {
        if (s[i] >= s[pos])
        {
            return false;
        }
        pos = i;
    }
    return true;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    FOR(i, 0, n)
    {
        int s;
        string phone;
        cin >> s >> name[i];
        FOR(j, 0, s)
        {
            cin >> phone;
            if (isTaxi(phone))
            {
                ++cnt[i][0];
            }
            else if (isPizza(phone))
            {
                ++cnt[i][1];
            }
            else
            {
                ++cnt[i][2];
            }
        }
        FOR(j, 0, 3) { mx[j] = max(mx[j], cnt[i][j]); }
        // cout << cnt[i][0] << ' ' << cnt[i][1] << ' ' << cnt[i][2] << '\n';
    }
    // cout << mx[0] << ' ' << mx[1] << ' ' << mx[2] << '\n';
    FOR(i, 0, 3)
    {
        bool delimiter = false;
        cout << message[i];
        FOR(j, 0, n) if (mx[i] == cnt[j][i])
        {
            if (delimiter)
            {
                cout << ',';
            }
            delimiter = true;
            cout << ' ' << name[j];
        }
        cout << ".\n";
    }
}
