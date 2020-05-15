/*
source: ABC 126 E 1 or 2
*/
#include <bits/stdc++.h>
using namespace std;
const int MXN = 100005;
int p[MXN], r[MXN];

void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        p[i] = i;
        r[i] = 1;
    }
}

int Find(int x)
{
    return (x == p[x] ? x : p[x] = Find(p[x]));
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)
    {
        return false;
    }
    if(r[x] == r[y])
    {
        p[y] = x;
        ++r[x];
    }
    else if(r[x] > r[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    init(n);
    for(int i = 0, x, y, z; i != m; ++i)
    {
        cin >> x >> y >> z;
        if(Union(x, y))
        {
            --n;
        }
    }
    cout << n << '\n';
}