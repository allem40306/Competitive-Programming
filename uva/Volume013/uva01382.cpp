#include <bits/stdc++.h>
using namespace std;
const int N = 105;

struct Point{
    int x, y;
    bool operator<(const Point&rhs)const{
        return x < rhs.x;
    }
};

Point p[N];
int n, m;
int on[N], on2[N], Left[N];
vector<int>y;

int sol(){
    sort(p, p + n);
    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    if(y.size() <= 2)return n;
    int ans = 0;
    for(unsigned i = 0; i != y.size(); ++i){
        for(unsigned j = i + 1; j != y.size(); ++j){
            int k = 0;
            for(int a = 0; a < n; ++a){
                if(!a || p[a].x != p[a - 1].x){
                    ++k;
                    on[k] = on2[k] = 0;
                    Left[k] = Left[k - 1] + (on2[k - 1] - on[k - 1]);
                }
                if(y[i] < p[a].y && p[a].y < y[j])++on[k];
                if(y[i] <= p[a].y && p[a].y <= y[j])++on2[k];
            }
            if(k <= 2)return n;
            int mx = 0;
            for(int a = 1; a <= k; ++a){
                ans = max(ans, Left[a] + on2[a] + mx);
                mx = max(mx, on[a] - Left[a]);
            }
        }
    }
    return ans;
}

int main(){
    int cas = 0;
    while(cin >> n, n){
        for(int i = 0; i < n; ++i){
            cin >> p[i].x >> p[i].y;
            y.push_back(p[i].y);
        }
        cout << "Case " << ++cas << ": " << sol() << '\n';
    }
}