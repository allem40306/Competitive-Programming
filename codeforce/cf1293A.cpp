#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int t, n, s, k;
    set<int> st;
    cin >> t;
    while(t--)
    {
        st.clear();
        cin >> n >> s >> k;
        for (int i = 0, x; i != k; ++i)
        {
            cin >> x;
            st.insert(x);
        }
        for (int i = 0; s + i <= n || s - i > 0; ++i)
        {
            if(s + i <= n && st.count(s + i) == 0)
            {
                cout << i << '\n';
                break;
            }
            if(s - i > 0 && st.count(s - i) == 0)
            {
                cout << i << '\n';
                break;
            }
        }
    }
}