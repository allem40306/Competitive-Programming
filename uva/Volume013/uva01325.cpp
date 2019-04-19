#include <bits/stdc++.h>
using namespace std;
#define p2(x, y) ((x - y) * (x - y))
const int N = 1005;
struct Point{
    int x, y, z, p;
};

Point p[N];

struct Edge{
    int from, to, w;
    bool operator<(const Edge&rhs)const{
        return w < rhs.w;
    }
};

vector<Edge>edges;
int same[N];

int main(){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            same[i] = 1;
            cin >> p[i].x >> p[i].y >> p[i].z >> p[i].p;
        }
        edges.clear();
        for(int i = 1; i <= n; ++i){
            for(int j = i + 1; j <=n; ++j){
                static int d; d = p2(p[i].x, p[j].x) + p2(p[i].y, p[j].y) + p2(p[i].z, p[j].z);
                edges.push_back({i, j, d});
            }
        }
        sort(edges.begin(), edges.end());
        int tmp = 0, mnr = 0, mxp = 0, i = 0;
        while(i != edges.size()){
            int j = i;
            while(j != edges.size() && edges[j].w == edges[i].w){
                int u = edges[j].from, v = edges[j].to;
                if(p[u].p ^ p[v].p){
                    if(--same[u] == -1)++tmp;
                    if(--same[v] == -1)++tmp;
                }else{
                    if(++same[u] == 0)--tmp;
                    if(++same[v] == 0)--tmp;
                }
                j++;
            }
            if(tmp > mxp){
                mxp = tmp;
                mnr = edges[i].w;
            }
            i = j;
        }
        cout << mxp << '\n';
        cout << fixed << setprecision(4) << sqrt((double)mnr) << '\n';
    }
}