#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
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
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n;
    string s, r = "+-*%";
    cin >> n;
    while (n--)
    {
        cin >> s;
        bool ok = true;
        for (int i = 0; i < 9; ++i)
        {
            if (i % 3 == 1 && r.find(s[i]) == string::npos)
            {
                ok = false;
                break;
            }
            if (i % 3 != 1 && !isalnum(s[i]))
            {
                ok = false;
                break;
            }
        }
        if (ok == false)
        {
            cout << "error\n";
            continue;
        }
        queue<int> num;
        queue<char> op;

        for (int i = 0; i < 3; ++i)
        {
            num.push((int(s[i * 3] - '0') + 7) % 10);
            num.push((int(s[(2 - i) * 3 + 2] - '0') + 7) % 10);
        }
        op.push(s[4]);
        op.push(s[1]);
        op.push(s[4]);
        op.push(s[7]);
        op.push(s[4]);

        stack<int> num2;
        stack<char> op2;

        num2.push(num.front());
        num.pop();
        while(!num.empty())
        {
            int y = num.front();
            num.pop();
            char ch = op.front();
            op.pop();
            if(ch == '+' || ch == '-')
            {
                num2.push(y);
                op2.push(ch);
            }
            else if(ch == '*')
            {
                int x = num2.top();
                num2.pop();
                num2.push(x * y);
            }
            else
            {
                int x = num2.top();
                num2.pop();
                num2.push(x / y);
            }
        }
        while(num2.size()>1)
        {
            int y = num2.top();
            num2.pop();
            int x = num2.top();
            num2.pop();
            char ch = op2.top();
            op2.pop();
            if(ch == '+')
            {
                num2.push(x + y);
            }
            else
            
            {
                num2.push(x - y);
            }
        }
        cout << num2.top() << '\n';
    }
}
