#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;

int main(){
    int q;
    LL n, m;
    vector<LL> v(15);
    cin >> q;
    while(q--)
    {
        v.clear();
        cin >> n >> m;
        v[0] = 0;
        for(int i = 1; i != 10; ++i)
        {
            v[i] = m * i % 10 + v[i - 1];
        }
        v[10] = v[9];
        LL tmp = n / m;
        cout << (tmp / 10) * v[10] + v[tmp % 10] << '\n';
    }
}