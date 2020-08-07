#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
const int INF = 1e9;
const int MXN = 1e5 + 5;
const int MXV = 3e5 + 5;
const ULL MOD = 10009;
const ULL seed = 31;
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

int fail[MXN];
void bulid_fail_funtion(string B)
{
    int len = B.length(), current_pos;
    current_pos = fail[0] = -1;
    for (int i = 1; i < len; i++)
    {
        while (current_pos != -1 && B[current_pos + 1] != B[i])
        {
            current_pos = fail[current_pos];
        }
        if (B[current_pos + 1] == B[i])
        {
            current_pos++;
        }
        fail[i] = current_pos;
    }
}

int match(string A, string B)
{
    int lenA = A.size(), lenB = B.size();
    int current_pos = -1;
    int ans = 0;
    for (int i = 0; i < lenA; i++)
    {
        while (current_pos != -1 && B[current_pos + 1] != A[i])
        {
            current_pos = fail[current_pos];
        }
        if (B[current_pos + 1] == A[i])
            current_pos++;
        if (current_pos == lenB - 1)
        { // match! A[i-lenB+1,i]=B
            current_pos = fail[current_pos];
            ++ans;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, r;
        cin >> s >> r;
        bulid_fail_funtion(s);
        cout << match(r, s) << '\n';
    }
}