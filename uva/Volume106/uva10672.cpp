#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> G[N];
int ball[N];
bitset<N> is_root;

void init(int n){
    is_root.set();
    for(int i = 0, x, y, z; i < n; ++i){
        cin >> x;
        G[x].clear();
        cin >> ball[x] >> y;
        while(y--){
            cin >> z;
            is_root[z] = false;
            G[x].push_back(z);
        }
    }
}
int ans;

int dfs(int s){
    int tmp = ball[s] - 1;
    for(auto it: G[s]){
        tmp += dfs(it);
    }
    ans += abs(tmp);
    // cout << "de:" << s << ' ' << tmp << '\n';
    return tmp;
}

int main(){
    int n;
    while(cin >> n, n){
        init(n);
        ans = 0;
        for(int i = 1; i <= n; i++){
            if(is_root[i])dfs(i);
        }
        cout << ans << '\n';
    }
} 
