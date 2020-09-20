#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int,int>;
const LL INF = 1e18;
const int MXV = 2e5 + 5;
const LL MOD = 1e9 + 7;
#define MP make_pair
string s, srp = "SRP", op = "+-*";
vector<int> G[MXV];
map<PII ,LL> ans;
int tb[3][3][3]={{{0,1,0},{1,1,2},{0,2,2}},
                {{0,0,2},{0,1,1},{2,1,2}},
                {{0,2,1},{2,1,0},{1,0,2}}}; // tb: table

string toPostfix(string s)
{
    deque<char> st;
    string res = "";
    for(int i = 0; i < (int)s.size(); ++i)
    {
        char ch = s[i];
        // cout << ch << ' ' << res << '\n';
        if(ch == '(')
        {
            st.push_back(ch);
        }
        else if(ch == ')')
        {
            while(!st.empty() && st.back() != '(')
            {
                res += st.back();
                st.pop_back();
            }
            st.pop_back();
        }
        else if(ch == '*')
        {
            while(!st.empty() && st.back() == '*')
            {
                res += st.back();
                st.pop_back();
            }
            st.push_back(ch);
        }
        else if(ch == '+' || ch == '-')
        {
            while(!st.empty() && st.back() != '(')
            {
                res += st.back();
                st.pop_back();
            }
            st.push_back(ch);
        }
        else
        {
            res += ch;
        }
    }
    while(!st.empty())
    {
        res += st.back();
        st.pop_back();
    }
    return res;
}

void buildG(string s)
{
    deque<int> st;
    for(int i = 0; i < (int)s.size(); ++i)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*')
        {
            assert((int)st.size() >= 2);
            for(int j = 0; j < 2; ++j)
            {
                if(st.empty()){cout << "error\n";}
                int v = st.back();
                st.pop_back();
                G[i].push_back(v);
                // cout << i << ' ' << v << '\n';
            }
        }
        st.push_back(i);
    }
}

LL dfs(int state, int tar)
{
    // cout << state << ' ' << tar << '\n';
    if(ans.find({state, tar}) != ans.end())
    {
        return ans[MP(state, tar)];
    }
    char ch = s[state];
    if(isalpha(ch) || ch == '?')
    {
        if(ch == '?' || ch == srp[tar])
        {
            // printf("[%d,%d]=%lld\n", state, tar, 1LL);
            return ans[MP(state, tar)] = 1LL;
        }
        // printf("[%d,%d]=%lld\n", state, tar, 0LL);
        return ans[MP(state, tar)] = 0LL;
    }
    int x = op.find(ch);
    LL tmp = 0;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(tb[x][i][j] == tar)
            {
                // cout << state << ':' << x << ' ' << i << ' ' << j << '\n';
                tmp += (dfs(G[state][0], i) * dfs(G[state][1], j)) % MOD;
                tmp = (tmp + MOD) % MOD;
            }
        }
    }
    tmp = (tmp + MOD) % MOD;
    // printf("[%d,%d]=%lld\n", state, tar, tmp);
    return ans[MP(state, tar)] = tmp;
}

int main()
{
    int n;
    char ch;
    cin >> n >> s;
    s = toPostfix(s);
    buildG(s);
    n = (int)s.size();
    cin >> ch;
    cout << dfs(n - 1, srp.find(ch)) << '\n';
}