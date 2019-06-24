#include <bits/stdc++.h>
using namespace std;

int main(){
    double L, n, C;
    while(cin >> L >> n >> C){ 
        if(L < 0 && n < 0 && C < 0)break;
        double S = (1 + n * C) * L, tmp;
        double LL = 0.0, RR = L * 0.5, M = (LL + RR) / 2;
        while(fabs(RR - LL) > 1e-6){
            M = (LL + RR) / 2;
            tmp = (4 * M * M + L * L) / 8.0 / M;
            if(2 * tmp * asin(L / 2 / tmp) < S){
                LL = M;
            }else{
                RR = M;
            }
        }
        cout << fixed << setprecision(3) << M << '\n';
    }
}