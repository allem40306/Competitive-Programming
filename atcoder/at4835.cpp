/*
source: ABC 141 F Xor Sum 3
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MXN = 100005;

int main(){
    int n;
    LL a[MXN], b[MXN], sum = 0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i = 0; i < n; ++i)
    {
        a[i] &= (~sum);
        for(int j = 60; j >= 0; --j)
        {
            if((a[i] >> j) & 1)
            {
                if(b[j] == 0)
                {
                    b[j] = a[i];
                    break;
                }
                else
                {
                    a[i] ^= b[j];
                }
            }
        }
    }
    LL x = 0;
    for(int i = 60; i >= 0; --i)
    {
        x = max(x, x ^ b[i]);
    }
    cout << (x + (x ^ sum)) << '\n';
}