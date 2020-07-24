#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
const int INF = 1e9;
const int MXN = 1e3 + 5;
const int MXV = 0;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i != (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i != (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
LL b;

struct Type
{
    LL price;
    int quality;
};

vector<Type> v[MXN];
map<string, int> typeId;
int id;

int getTypeId(string type)
{
    if(typeId.find(type) == typeId.end())
    {
        typeId.insert({type, ++id});
    }
    return typeId[type];
}

vector<Type> types[MXN];

bool ok(int x)
{
    // cout << "test " << x << '\n';
    LL sum = 0;
    FOR(i, 0, id + 1)
    {
        LL mn = b + 1;
        for(Type type: types[i])
        {
            if(type.quality >= x)
            {
                mn = min(mn, type.price);
            }
        }
        sum += mn;
        // cout << "type " << i << ": " << mn << '(' << sum << ')' << '\n';
    }
    return sum <= b;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> b;
        FOR(i, 0, n) { types[i].clear(); }
        id = -1;
        typeId.clear();
        int maxq = 0;
        FOR(i, 0, n)
        {
            string type, name;
            int price, quality;
            cin >> type >> name >> price >> quality;
            types[getTypeId(type)].push_back(Type{price, quality});
            maxq = max(maxq, quality);
        }
        int L = 0, R = maxq;
        while(L != R)
        {
            int M = (L + R + 1) >> 1;
            if(ok(M))
            {
                L = M;
            }
            else
            {
                R = M - 1;
            }
        }
        cout << L << '\n';
    }
}