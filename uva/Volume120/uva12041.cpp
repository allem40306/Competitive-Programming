#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;
LL x, y;
LL f[N];

void init(){
    f[0] = f[1] = 1;
    for(int i = 2; i < N; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
}

void bfs(LL L, LL R, int d, int Sign){
    // cout << "de:" << L << ' ' << R << '\n';
    if(L > y || R < x)return;
    if(L == R){
        cout << Sign;
        return;
    }
    bfs(L, L + f[d - 2] - 1, d - 2, Sign);
    bfs(L + f[d - 2], R, d - 1, 1 - Sign);
}

int main(){
    int t, n;
    init();
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        static int cnt;
        for(int i = 0; i < N; ++i){
            if((i % 2 == n % 2) && f[i] > y){
                cnt = i;
                break;
            }
        }
        int sign = cnt % 2;
        bfs(0, f[cnt] - 1, cnt, sign);
        cout << '\n';
    }
}