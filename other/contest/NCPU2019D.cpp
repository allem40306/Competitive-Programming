#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct Data{
    string S;
    int s, r;
    bool operator<(const Data &rhs)const
    {
        if(s != rhs.s)
        {
            return s > rhs.s;

        }
        return S < rhs.S;
    }
};


int main()
{
    int n, m;
    Data a[N];
    cin >> n;
    while(n--)
    {

        cin >> m;
        for(int i = 0; i != m; ++i)
        {
            cin >> a[i].S >> a[i].s >> a[i].r;
        }
        sort(a, a + m);
        for(int i = 0, j = 0; i < 3; ++i)
        {
            while(j != m && a[j].r > 1000)
            {
                ++j;
            }
            if(j == m)
            {
                break;
            }
            cout << a[j].S << ' '<< a[j].s << '\n' ;
            ++j;
        }

    }
}
