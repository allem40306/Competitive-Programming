#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int,int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9+7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for(int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for(int i = L; i > (int)R; --i)
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
struct Data {
    string name;
    int parameter;
    int priority;
    bool operator<(const Data &rhs) const { return priority > rhs.priority; }
};

int main()
{
    IOS;
    priority_queue<Data> pq;
    string s,name;
    int parameter;
    int priority;
    while(cin >> s)
    {
        if(s=="PUT")
        {
            cin >> name >> parameter >> priority;
            pq.push({name, parameter, priority});
        }
        else
        {
            if(pq.empty())
            {
                cout << "EMPTY QUEUE!\n";
            }
            else
            {
                auto k = pq.top();
                pq.pop();
                cout << k.name << ' ' << k.parameter << '\n';
            }
        }
    }
}
