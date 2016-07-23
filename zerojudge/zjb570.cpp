#include <iostream>
using namespace std;
#define N 1100000

static int p[N];
void init(){
	for (int i = 0; i < N; i++)
		p[i] = i;
}
int find(int x){
	return x == p[x] ? x : p[x] = find(p[x]);
}

struct budget{
	int a, b;
};

int uni(int a, int b){
	int fa = find(a), fb = find(b);
	if (fa == fb)return false;
	p[fa] = fb;
	return true;
}

int main() {
	static int n, m, q, qq[N];
	while (cin >> n >> m){
		init();
		static budget b[N];
		for (int i = 0; i < N; i++)
			b[i].a = b[i].b = 0;
		for (int i = 0; i < m; i++)
			cin >> b[i].a >> b[i].b;
		cin >> q;
		static int ans[N], vis[N] = {};
		for (int i = 0; i < q; i++){
			cin >> qq[i];
			qq[i]--;
			vis[qq[i]] = 1;;
		}
		int tans = n;
		for (int i = 0; i < m; i++)
			if (!vis[i]){
			if (uni(b[i].a, b[i].b))tans--;
			}
		for (int i = q - 1; i >= 0; i--){
			ans[i] = tans;
			if (uni(b[qq[i]].a, b[qq[i]].b))tans--;
		}
		for (int i = 0; i < q; i++){
			cout << ans[i] << endl;
		}
	}
}
