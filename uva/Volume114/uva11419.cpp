#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int r, c, n;
int Left[N];
vector<int> G[N];
bitset<N> vx, vy, mark;

void add_Edge(int x, int y){
    G[x].push_back(y);
}

void init(int n){
    for(int i = 1; i <= r; i++){
        G[i].clear();
    }
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        add_Edge(x, y);
    }
}

bool match(int i) {
	vx[i] = true;
	for (int j: G[i]) {
		if (!vy[j]) {
			vy[j] = true;
			if (!Left[j] || match(Left[j])) {
				Left[j] = i;
				return true;
			}
		}
	}
	return false;
}

void KM(){
    int ret = 0;
    memset(Left, 0,sizeof(Left));
	for (int i = 1; i <= r; i++) {
		vx.reset(); vy.reset();
		if (match(i))ret++;
	}
    cout << ret;
}

void sol(){
    KM();

    vx.reset(); vy.reset(); mark.reset();
    for(int i = 1; i <= c; i++)mark[Left[i]] = true;
    for(int i = 1; i <= r; i++)if(!mark[i])match(i);

    for(int i = 1; i <= r; i++)if(!vx[i])cout << " r" << i;
    for(int i = 1; i <= c; i++)if(vy[i])cout << " c" << i;
    cout << '\n';
}

int main(){
    while(cin >> r >> c >> n, r || c || n){
        init(n);
        sol();
    }
}