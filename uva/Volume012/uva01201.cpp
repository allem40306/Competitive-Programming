#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 505;
vector<int> G[N];
int L[N], R[N];
int Left[N];
bitset<N> vx, vy;
PII A[N], B[N];

int dis(PII x, PII y){
    return abs(x.first - y.first) + abs(x.second - y.second);
}

void init(int n){
    for(int i = 1; i <= n; ++i)G[i].clear();
    for(int i = 1; i <= n; ++i){
        static int h, m, a, b, c, d;
        static char ch;
        cin >> h >> ch >> m >> a >> b >> c >> d;
        L[i] = h * 60 + m;
        A[i] = {a, b};
        B[i] = {c, d};
        // cout << "de:" << i << ' ' << L[i] << ' ' << R[i] << '\n';
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i != j && L[i] + dis(A[i], B[i]) + dis(B[i], A[j]) < L[j]){
                G[i].push_back(j);
                // cout << "de:" <<i<<j<<'\n';
                // cout << L[i] + dis(A[i], B[i]) + dis(B[i], A[j]) << ' ' << L[j] << '\n';
            }
        }
    }
}

bool match(int i){
    vx[i] = true;
    for(int j: G[i]){
        if(!vy[j]){
            vy[j] = true;
            if(!Left[j] || match(Left[j])){
                Left[j] = i;
                return true;
            }
        }
    }
    return false;
}

int KM(int n){
    memset(Left, 0, sizeof(Left));
    static int ret; ret = 0;
    for(int i = 1; i <= n; ++i){
        vx.reset(); vy.reset();
        if(match(i))ret++;
    }
    return ret;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        init(n);
        cout << n - KM(n) << '\n';
    }
}