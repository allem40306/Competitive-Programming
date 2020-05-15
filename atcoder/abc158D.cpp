#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i != (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    deque<char> dq;
    string s;
    int q;
    bool r = false;
    cin >> s >> q;
    FOR(i, 0, s.size()) { dq.push_back(s[i]); }
    while(q--)
    {
        int a, b;
        char c;
        cin >> a;
        if(a == 1)
        {
            r = !r;
        }
        else
        {
            cin >> b >> c;
            if(r ^ (b & 1))
            {
                dq.push_front(c);
            }
            else
            {
                dq.push_back(c);
            }
        }
    }
    if(r)
    {
        while(!dq.empty()){
            cout << dq.back();
            dq.pop_back();
        }
    }
    else
    {
        while(!dq.empty()){
            cout << dq.front();
            dq.pop_front();
        }
    }
    cout << '\n';
}
