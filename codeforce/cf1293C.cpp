#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
const int MXN = 100005;
#define IOS cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);

int main()
{
    IOS;
    int n, q;
    bitset<MXN> isup[3], isblocked[3];
    for (int i = 0; i < 3; ++i)
    {
        isup[i].reset();
        isblocked[i].reset();
    }
    cin >> n >> q;
    int notOKCnt = 0;
    for (int i = 0, r, c, rr; i != q; ++i)
    {
        cin >> r >> c;
        rr = 3 - r;
        if(isup[r][c])
        {
            if(isup[rr][c - 1] && isblocked[rr][c - 1])
            {
                isblocked[rr][c - 1] = false;
                --notOKCnt;
            }
            if(isup[rr][c + 1] && isblocked[r][c])
            {
                isblocked[r][c] = false;
                --notOKCnt;
            }
            if(isup[rr][c] && isblocked[0][c])
            {
                isblocked[0][c] = false;
                --notOKCnt;
            }
        }
        else
        {
            if(isup[rr][c - 1] && !isblocked[rr][c - 1])
            {
                isblocked[rr][c - 1] = true;
                ++notOKCnt;
            }
            if(isup[rr][c + 1] && !isblocked[r][c])
            {
                isblocked[r][c] = true;
                ++notOKCnt;
            }
            if(isup[rr][c] && !isblocked[0][c])
            {
                isblocked[0][c] = true;
                ++notOKCnt;
            }
        }
        isup[r][c] = !isup[r][c];
        // cout << notOKCnt << '\n';
        if(notOKCnt == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}