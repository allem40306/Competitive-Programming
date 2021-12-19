#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
const int INF = 1e9;
const int MXN = 0;
const int MXV = 0;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);

map<int, int> T;
vector<int> order;

void bfs()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        if (T.find(pos) == T.end())
        {
            continue;
        }
        order.emplace_back(T[pos]);
        q.push(2 * pos);
        q.push(2 * pos + 1);
    }
}

int main()
{
    IOS;
    string s;
    while (cin >> s)
    {
        int nodeCnt = 0;
        T.clear();
        while (s != "()")
        {
            ++nodeCnt;
            int val = 0, pos = 1;
            int i = 1;
            for (;; ++i)
            {
                if (s[i] == ',')
                    break;
                val = val * 10 + (s[i] - '0');
            }
            ++i;
            for (;; ++i)
            {
                if (s[i] == ')')
                    break;
                pos = pos * 2 + (s[i] == 'L' ? 0 : 1);
            }
            T.insert({pos, val});
            cin >> s;
        }
        order.clear();
        bfs();
        if ((int)order.size() != nodeCnt)
        {
            cout << "not complete\n";
            continue;
        }
        FOR(i, 0, order.size())
        {
            cout << order[i] << " \n"[i == (int)order.size() - 1];
        }
    }
}
