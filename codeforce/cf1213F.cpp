#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), ansTag;
    for(int i = 0; i != n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 0; i != n; ++i)
    {
        cin >> b[i];
    }
    set<int> s1, s2;
    for(int i = 0; i != n; ++i)
    {
        if(s2.count(a[i]))
        {
            s2.erase(a[i]);
        }
        else
        {
            s1.insert(a[i]);
        }
        if (s1.count(b[i]))
        {
            s1.erase(b[i]);
        }
        else
        {
            s2.insert(b[i]);
        }
        if(s1.empty() && s2.empty())
        {
            ansTag.push_back(i);
        }        
        
        
    }
    if((int)ansTag.size() < k)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        int j = 0;
        string ans(n, ' ');
        for(int i = 0; i != n; ++i)
        {
            ans[a[i] - 1] = char('a' + min(j, 25));
            if(i == ansTag[j])
            {
                j++;
            }
        }
        cout << ans << '\n';
    }
    
}