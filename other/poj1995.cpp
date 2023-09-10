#include <iostream>
using namespace std;

long long fPow(long long a, long long b, long long c)
{
    long long ret = 1;
    for (; b > 0; b >>= 1)
    {
        if (b & 1)
            ret = (ret * a) % c;
        a = (a * a) % c;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long m,a,b;
        long long ans = 0;
        int n;
        cin >> m >> n;
        for(int i = 0; i <n;++i)
        {
            cin >> a >> b;
            ans = (ans + fPow(a, b, m)) % m;
        }
        cout << ans << '\n';
    }
}
