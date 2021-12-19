#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        queue<char> q;
        stack<char> ops;
        cin >> s;
        for(int i = 0; i != (int)s.size(); ++i)
        {
            if(isalnum(s[i]))
            {
                q.push(s[i]);
            }
            else
            { 
                if(s[i] == '+')
                {
                    while(!ops.empty())
                    {
                        q.push(ops.top());
                        ops.pop();
                    }
                }
                ops.push(s[i]);
            }
            
        }
        while(!ops.empty())
        {
            q.push(ops.top());
            ops.pop();
        }
        stack<int> st;
        while(!q.empty())
        {
            char ch = q.front(); q.pop();
            if(isalnum(ch))
            {
                st.push((int)(ch - '0'));
            }
            else
            {
                int rhs = st.top(); st.pop();
                int lhs = st.top(); st.pop();
                if(ch == '+')
                {
                    lhs += rhs;
                }
                else
                {
                    lhs *= rhs;
                }
                st.push(lhs);                
            } 
        }
        cout << st.top() << '\n';
    }
}