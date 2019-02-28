#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 505;
const int M = 55;
int n, m;
int a[M], v[M][M];
int w[N][N], Left[N], Lx[N], Ly[N];
bitset<N> vx,vy;

bool match(int i){
    vx[i] = true;
    for(int j = 1; j <= m; j++){
        if((Lx[i] + Ly[j] - w[i][j]) == 0 && !vy[j]){
            vy[j] = true;
            if(!Left[j] || match(Left[j])){
                Left[j] = i;
                return true;
            }
        }
    }
    return false;
}

void update(){
    int a = INF;
    for(int i = 1; i <= n; i++){
        if(vx[i])for(int j = 1; j <= m; j++){
            if(!vy[j])a = min(a, Lx[i] + Ly[j] - w[i][j]);
        }
    }
    for(int i = 1;i <= n; i++)if(vx[i])Lx[i] -= a;
    for(int i = 1;i <= m; i++)if(vy[i])Ly[i] += a;
}

void KM(){
    for(int i = 1; i <= n; i++){
        Lx[i] = -INF;
        for(int j = 1; j <= m; j++){
            Lx[i] = max(Lx[i], w[i][j]);
        }
    }
    for(int i = 1; i <= m; i++)Left[i] = Ly[i] = 0;
    for(int i = 1; i <= n; i++){
        while(true){
            vx.reset(); vy.reset();
            if(match(i))break;
            update();
        }
    }
}

void init(){
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    memset(v, INF, sizeof(v));
    for(int i = 1, k, s, t; i <= n; i++){
        cin >> k;
        while(k--){
            cin >> s >> t;
            for(int j = 1; j <= m; j++){
                if(a[j] >= s)v[i][j] = min(v[i][j], t);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){ // memory j
            for(int p = 1; p <= n; p++){ // last p 
                int vv = (j - 1) * n + p;
                if(v[i][j] == INF)w[i][vv] = -INF;
                else w[i][vv] = - p * v[i][j];
            }
        }
    }
    m *= n;
}

int main(){
    int ti = 0;
    while(cin >> m >> n, m || n){
        init();
        KM();
        double ans = 0;
        for(int i = 1; i <= n; i++)ans +=Lx[i];
        for(int i = 1; i <= m; i++)ans +=Ly[i];
        if(ti)cout << '\n';
        cout << "Case " << ++ti << '\n';
        cout << fixed << setprecision(2) << "Average turnaround time = " << (-ans / n) << '\n';
        int p[M] = {}, rs[M], rt[M];
        for(int i = 1; i <= m; i++){
            if(!Left[i])continue;
            int rg = (i - 1) / n + 1;
            p[rg] += v[Left[i]][rg];
            // cout<< "de:" << Left[i] << ' ' << rg << '\n';
            rs[Left[i]] = rg;
            rt[Left[i]] = p[rg];
        }
        for(int i = 1; i <= n; i++){
            int s = p[rs[i]] - rt[i];
            cout << "Program " << i << " runs in region " << rs[i] << " from " << s << " to " << s + v[i][rs[i]] << "\n";
        }
    }
}