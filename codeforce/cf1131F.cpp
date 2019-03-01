#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n;
int p[N], L[N], R[N], tot;
bool o = false;

void init(int n){
    for(int i = 0; i <= (n << 1); i++){
        p[i] = i;
    }
    tot = n + 1;
    return;
}

int f(int x){return ((x == p[x])?(x):(p[x] = f(p[x])));}

void Union(int x, int y){
    int fx = f(x), fy = f(y);
    p[fx] = p[fy] = tot;
    L[tot] = fx; R[tot] = fy;
    tot++;
    return;
}

void dfs(int p){
    // cout << "de:" << p << L[p] << R[p] <<'\n';
    if(p <= n){
        if(o)cout<<' '; o = true;
        cout << p;
        return;
    }
    dfs(L[p]);
    dfs(R[p]);
}

int main(){
    cin >> n;
    init(n);
    for(int i = 0, x, y; i < n - 1; i++){
        cin >> x >> y;
        Union(x,y);
    }
    dfs(tot - 1);
}