#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 1e4 + 5;
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
    int n, a[MXN], L[MXN], R[MXN];
    stack<int> st;
    cin >> n;
    a[0] = a[n + 1] = 0;
    FOR(i, 1, n + 1) cin >> a[i];
    st.push(0);
    FOR(i, 1, n + 1)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        L[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    st.push(n + 1);
    FORD(i, n, 0)
    {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        R[i] = st.top() - 1;
        st.push(i);
    }
    int ans = 0;
    FOR(i, 1, n + 1)
    {
        ans = max(ans, a[i] * (R[i] - L[i] + 1));
    }
    cout << ans << '\n';
}
