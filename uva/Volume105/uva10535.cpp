#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);

struct State{
    double t;
    int k;
    bool operator<(const State &rhs)const{
        if(t != rhs.t)
            return t < rhs.t;
        return k > rhs.k;
    }
};

struct Loc{
    double x1, y1, x2, y2;
};

vector<State> vs;
vector<Loc> vL;

void init(int n){
    double x, y;
    vL.resize(n);
    vs.clear();
    for(int i = 0; i != n; ++i){
        cin >> vL[i].x1 >> vL[i].y1 >> vL[i].x2 >> vL[i].y2;
    }
    cin >> x >> y;
    for(auto it: vL){
        double L = atan2(it.y1 - y, it.x1 - x);
        double R = atan2(it.y2 - y, it.x2 - x);
        if(L > R){
            swap(L, R);
        }
        if(R - L >= pi){
            vs.push_back(State{-pi, 1});
            vs.push_back(State{L, -1});
            L = R; R = pi;
        }
        vs.push_back(State{L, 1});
        vs.push_back(State{R, -1});
    }
    sort(vs.begin(), vs.end());
}

int solve(){
    int ans = 0, tmp = 0;
    for(auto it: vs){
        // cout << it.t << '-' << it.k << '\n';
        tmp += it.k;
        ans = max(ans, tmp);
    }
    return ans;
}

int main(){
    int n;
    while(cin >> n, n){
        init(n);
        cout << solve() << '\n';
    }
}