#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MXN = 5e5 + 5;
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
#define LC(x) ((x << 1))
#define RC(x) ((LC(x)) | 1)
LL seg[(MXN << 2)], tag[(MXN << 2)];

void pull(int rt, int L, int R)
{
    int M = (L + R) >> 1;
    tag[LC(rt)] += tag[rt];
    seg[LC(rt)] += (M - L + 1) * tag[rt];
    tag[RC(rt)] += tag[rt];
    seg[RC(rt)] += (R - M) * tag[rt];
    tag[rt] = 0;
}

void update(int rt, int L, int R, int qL, int qR, LL val)
{
    if (qL <= L && R <= qR)
    {
        seg[rt] += (R - L + 1) * val;
        tag[rt] += val;
        return;
    }
    pull(rt, L, R);
    int M = (L + R) >> 1;
    if (qL <= M)
        update(LC(rt), L, M, qL, qR, val);
    if (M + 1 <= qR)
        update(RC(rt), M + 1, R, qL, qR, val);
    seg[rt] = seg[LC(rt)] + seg[RC(rt)];
}

LL query(int rt, int L, int R, int qL, int qR)
{
    if (qL <= L && R <= qR)
        return seg[rt];
    pull(rt, L, R);
    int M = (L + R) >> 1;
    if (qR < M + 1)
        return query(LC(rt), L, M, qL, qR);
    else if (M < qL)
        return query(RC(rt), M + 1, R, qL, qR);
    else
        return query(LC(rt), L, M, qL, qR) + query(RC(rt), M + 1, R, qL, qR);
}

int main()
{
    IOS;
    int n, q;
    cin >> n;
    FOR(i, 1, n + 1)
    {
        LL x;
        cin >> x;
        update(1, 1, n, i, i, x);
    }
    cin >> q;
    FOR(i, 0, q)
    {
        int typeId;
        cin >> typeId;
        if (typeId == 1)
        {
            int x, y;
            LL z;
            cin >> x >> y >> z;
            update(1, 1, n, x, y, z);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
}