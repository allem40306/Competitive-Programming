#include <bits/stdc++.h>
using namespace std;
const int N = 505;
struct Node{
    int height;
    string music, sport;
    bool ok(const Node& rhs)const{
        return height - rhs.height > 40 ||
            rhs.height - height > 40 ||
            music != rhs.music ||
            sport == rhs.sport;
    };
};
vector<Node>boy, girl;
vector<int>G[N];
int bs, gs;
int Left[N];
bitset<N> vx, vy;

void init(int n){
    static int h;
    static char g;
    static string m,s;
    boy.clear(); girl.clear();
    for(int i = 0; i < N; i++)G[i].clear();
    for(int i = 0; i < n; ++i){
        cin >> h >> g >> m >> s;
        if(g == 'M'){
            boy.push_back({h, m, s});
        }else{
            girl.push_back({h, m, s});
        }
    }
    bs = boy.size(); gs = girl.size();
    // cout << "de:" << bs << ' ' << gs <<'\n';
    for(int i = 0; i < bs; ++i){
        for(int j = 0; j < gs; ++j){
            if(!boy[i].ok(girl[j])){
                G[i].push_back(j);
            }
        }
    }
}

bool match(int i){
    vx[i] = true;
    for(int j: G[i]){
        if(!vy[j]){
            vy[j] = true;
            if(Left[j] == -1 || match(Left[j])){
                Left[j] = i;
                return true;
            }
        }
    }
    return false;
}

void sol(int n){
    memset(Left, -1,sizeof(Left));
    static int cnt; cnt = 0;
    for(int i = 0; i < bs;i++){
        vx.reset(); vy.reset();
        if(match(i))cnt++;
    }
    cout << n - cnt << '\n';
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        init(n);
        sol(n);
    }
}