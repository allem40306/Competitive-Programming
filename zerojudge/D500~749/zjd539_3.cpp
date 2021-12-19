#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
const int MXN = 5e5 + 5;
#define FOR(i, L, R) for (int i = L; i < (int)R; ++i)
#define FORD(i, L, R) for (int i = L; i > (int)R; --i)
#define IOS                                                                    \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);                                                         \
    ios_base::sync_with_stdio(false);
#define LC(x) ((x << 1))
#define RC(x) ((LC(x)) | 1)
int arr[MXN];
int seg[(MXN << 2)];

void update(int rt, int L, int R, int qL, int qR, int val)
{
    if (qL <= L && R <= qR)
    {
        seg[rt] = val;
        return;
    }
    int M = (L + R) >> 1;
    if (qL <= M)
        update(LC(rt), L, M, qL, qR, val);
    if (M + 1 <= qR)
        update(RC(rt), M + 1, R, qL, qR, val);
    seg[rt] = max(seg[LC(rt)], seg[RC(rt)]);
}

int query(int rt, int L, int R, int qL, int qR)
{
    if (qL <= L && R <= qR)
        return seg[rt];
    int M = (L + R) >> 1;
    if (qR < M + 1)
        return query(LC(rt), L, M, qL, qR);
    else if (M < qL)
        return query(RC(rt), M + 1, R, qL, qR);
    else
        return max(query(LC(rt), L, M, qL, qR),
                   query(RC(rt), M + 1, R, qL, qR));
}

int main()
{
    IOS;
    int n, q;
    cin >> n;
    FOR(i, 1, n + 1)
    {
        cin >> arr[i];
        update(1, 1, n, i, i, arr[i]);
    }
    cin >> q;
    FOR(i, 0, q)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        cout << query(1, 1, n, x, y) << '\n';
    }
}
