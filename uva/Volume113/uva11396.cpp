#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int color[N];
vector<int> v[N];

void init(int n){
    memset(color, -1, sizeof(color));
    for(int i = 0; i <= n; i++){
        v[i].clear();
    }
}

void addEdge(int f, int t){
    v[f].push_back(t);
    v[t].push_back(f);
}

bool isBipatirate(int s){
    for(auto it: v[s]){
        if(color[it] == -1){
            color[it] = 3 - color[s];
            if(!isBipatirate(it)) return false;
        }
        if(color[s] == color[it])return false;
    }
    return true;
}

int main(){
    int n;
    while(cin >> n, n){
        init(N);
        for(int x, y;cin >> x >> y, x || y; ){
            addEdge(x, y);
        }
        bool ok = true;
        for(int i = 1; i <= n; ++i){
            if(color[i] == -1){
                color[i] = 1;
                ok &= isBipatirate(i);
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}