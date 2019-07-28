#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    unsigned int y;
    string q;
    vector<int> v;
    cin >> n;
    while(n--)
    {
        cin >> q;
        if(q == "clear")
        {
            cin >> x;
            v.emplace_back(x);
        }
        else if(q == "query")
        {
            cin >> y;
            if(y > v.size())
            {
                cout << "FAT\n";
            }
            else
            {
                cout << v[y - 1] << '\n'; 
            }
            
        }
        else
        {
            v.pop_back();
        }
        
    }
}