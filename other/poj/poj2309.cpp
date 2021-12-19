#pragma GCC optimize(2)
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;
const int MXN = 1e6 + 5;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    ios_base::sync_with_stdio(false);
#define lowbit(x) (x&(-x))

int main()
{
    int t;
    long long n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        printf("%lld %lld\n", n - lowbit(n) + 1, n + lowbit(n) - 1);
    }
}