#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int INF = 1e9;
const int MXN = 1e3 + 5;
const int MXV = 1e5 + 5;
const LL MOD = 10009;
const LL seed = 31;
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

struct Node
{
    char ch;
    int v;
    Node *next[26];
    Node()
    {
        v = 0;
        FOR(i, 0, 26) next[i] = NULL;
    }
};

void insert(Node *root, string s)
{
    FOR(i, 0, s.size())
    {
        int v = s[i] - 'a';
        if (root->next[v] == NULL)
        {
            root->next[v] = new Node();
        }
        root = root->next[v];
        ++root->v;
        root->ch = s[i];
    }
    return;
}
void search(Node *root, string s)
{
    FOR(i, 0, s.size())
    {
        int v = s[i] - 'a';
        root = root->next[v];
        if (root->v == 1)
        {
            cout << s << ' ' << s.substr(0, i + 1) << '\n';
            return;
        }
    }
    cout << s << ' ' << s << '\n';
}

int main()
{
    vector<string> v;
    string s;
    Node *root = new Node();
    while (cin >> s)
    {
        insert(root, s);
        v.push_back(s);
    }
    FOR(i, 0, v.size()) { search(root, v[i]); }
}