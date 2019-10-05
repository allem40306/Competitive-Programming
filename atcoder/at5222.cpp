/*
source: ABC 140 F Many Slimes
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v, w;

bool sol()
{
    map<int, int, greater<int>> tb;
    for(int i = 1; i != (int) v.size(); ++i)
    {
        if(tb.find(v[i]) == tb.end())
        {
            tb[v[i]] = 0;
        }
        ++tb[v[i]];
    }
    w.push_back(v[0]);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < (1LL << i); ++j)
        {
            auto it = tb.upper_bound(w[j]);
            if(it == tb.end())
            {
                return false;
            }
            w.push_back((*it).first);
            --(*it).second;
            if((*it).second == 0)
            {
                tb.erase(it);
            }
        }
        sort(w.begin(), w.end(), greater<int>());
    }
    return true;
}

int main(){
    cin >> n;
    v.resize((1 << n));
    for(int i = 0; i != (1 << n); ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    if(sol())
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }   
    
}