#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int M = 20000005;
int s[N];
int tin[M], tout[M];
stack<int>st;
bitset<M>vis;

void dfs(int n){
    static int tot; tot = 0;
    vis.reset();
    while(!st.empty())st.pop();
    st.push(0);
    while(!st.empty()){
        int k = st.top();
        // cout << "de:" << k <<'\n';
        if(vis[k]){
            tout[k] = ++tot;
            // cout << "de:" << k << ' ' << tin[k] << ' ' << tout[k] << '\n';
            st.pop();
            continue;
        }
        vis[k] = 1;
        tin[k] = ++tot;
        for(int i = s[k] + 1; i <= s[k + 1]; ++i){
            if(i < n){
                st.push(i);
            }else{
                tin[i] = ++tot;
                tout[i] = ++tot;
            }
        }
    }
}

void init(int n){
    s[0] = 0;
    for(int i = 0, x; i < n; ++i){
        cin >> s[i + 1];
        s[i + 1] += s[i];
        // cout << "de: " << i << ' ' << s[i - 1] << ' ' << s[i] << '\n';
    }
    dfs(n);
}

void sol(int m){
    static int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        if(tin[x] < tin[y] && tout[y] < tout[x]){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}

int main(){
    int t, n, m;
    cin >> t;
    for(int ti = 0; ti < t;){
        cin >> n;
        init(n);
        if(ti)cout << '\n';
        cout << "Case " << ++ti << ":\n";
        cin >> m;
        sol(m);
    }
}