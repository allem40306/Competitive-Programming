#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
#define N 150010
#define P 500

int pp[N];
void init(){
	for (int i = 0; i < N; i++)
		pp[i] = i;
}
int find(int x){
	return x == pp[x] ? x : find(pp[x]);
}

struct loc{
	int x, y;
};

struct edge{
	int a, b, d;
};

bool cmp(edge a, edge b){
	return a.d < b.d;
}

int main() {
	int n, s, p;
	while (cin >> n){
		while (n--){
			loc a[P];
			edge e[N]; //N最後上傳要改150000
			int er = 0, i, j;
			cin >> s >> p;
			for ( i = 0; i < p; i++){
				cin >> a[i].x >> a[i].y;
				for ( j = 0; j < i; j++){
					e[er].a = i;
					e[er].b = j;
					e[er].d = (a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y);
					er++;
				}
			}
			sort(e, e + er, cmp);
			init();
			int nn = 0, ai = 0;
			int ans[P];
			for (i = 0; nn < p-1; i++){
				int fa = find(e[i].a), fb = find(e[i].b);
				if (fa != fb){
					pp[fa] = fb;
					ans[ai] = e[i].d;
					ai++;
					nn++;
				}
			}
			cout << fixed << setprecision(2) << sqrt(ans[nn-s]) << endl;
		}
	}
}