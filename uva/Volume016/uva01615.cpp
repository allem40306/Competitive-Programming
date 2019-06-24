#include <bits/stdc++.h>
using namespace std;
using T = long long;
T LL, D, N;

struct Village{
    T L, R;
    Village(){};
    Village(int x, int y){
        T t = sqrt(D * D - y * y);
        L = max((T)0, (T)ceil(x - t));
        R = min((T)LL, (T)floor(x + t));
    }
    bool operator<(const Village& rhs)const{
        return R < rhs.R;
    }
};

int main(){
    while(cin >> LL >> D >> N){
        vector<Village> v;
        for(int i = 0, x, y; i != N; ++i){
            cin >> x >> y;
            v.push_back(Village(x, y));
        }
        sort(v.begin(), v.end());
        T prev = v[0].R;
        int ans = 1;
        for(int i = 1; i != N; ++i){
            if(v[i].L > prev){
                ++ans;
                prev = v[i].R;
            }
        }
        cout << ans << '\n';
    }
}