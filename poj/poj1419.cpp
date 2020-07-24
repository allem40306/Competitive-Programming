#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 105;
int n;
int adj[N][N];
int tmp, ans;
int tmp_res[N], ans_res[N];

void dfs(int s){
    if(s > n){// all vertexes are searched
        memcpy(ans_res, tmp_res,sizeof(ans_res));
        ans = tmp;
        return;
    }
    bool ok = true;
    for(int i = 0; i < tmp; i++){
        if(adj[s][tmp_res[i]] == 0){
            ok = false;
            break;
        }
    }
    if(ok){// add vertex s
        tmp_res[tmp++] = s;
        dfs(s + 1);
        tmp--;
    }
    if(tmp + (n - s) > ans){// not to add vertex s
        dfs(s + 1);
    }
}

int main(){
    int t, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(adj, -1, sizeof(adj));
        for(int i = 0, x, y; i < m; i++){
            cin >> x >> y;
            adj[x][y] = adj[y][x] = 0;
        }
        tmp = ans = 0;
        dfs(1);
        cout << ans << '\n';
        for(int i = 0 ;i < ans; i++){
            if(i)cout<<' ';
            cout << ans_res[i];
        }
        cout << '\n';
    }
}