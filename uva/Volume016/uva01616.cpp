#include <bits/stdc++.h>
using namespace std;
const int MXM = 1000000 + 5;
int n;
vector<pair<int,int>>v;

bool ok(double x){
    double s = 0;
    for(int i = 0; i != n; ++i){
        if(s < v[i].first){
            if(v[i].first + x > v[i].second)return false;
            s = v[i].first + x;
        }else{
            if(s + x > v[i].second)return false;
            s += x;
        }
    }
    return true;
}

void solve(){
    double L = 0.0, R = (double)MXM, M;
    while(fabs(R - L) > 1e-9){
        M = (L + R) / 2;
        if(ok(M))L = M;
        else R = M;
    }
    double ans = L;
    int ansp = 0, ansq = 1;
    for(int i = 1; i <= n; ++i){
        int j = round(ans * i);
        if(fabs((double)j / i - ans) < fabs((double)ansp / ansq - ans)){
            ansp = j;
            ansq = i;
        }
    }
    cout << ansp << '/' << ansq << '\n';
}

void init(){
    v.clear();
    for(int i = 0, x, y; i < n; ++i){
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
}

int main(){
    while(cin >> n){
        init();
        solve();
    }
}