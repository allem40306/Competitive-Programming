#pragma GCC optimize(2)
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                          \
    cout.tie(NULL);                                                         \
    ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n;
    int ti = 0;
    while(cin >> n, n)
    {
        stack<string> st;
        string s;
        cout << "SET " << ++ti << '\n';
        FOR(i, 0, n)
        {
            cin >> s;
            if(i % 2)
            {
                st.push(s);
            }
            else
            {
                cout << s << '\n';
            }
        }
        while(!st.empty())
        {
            cout << st.top() << '\n';
            st.pop();
        }
    }
}
