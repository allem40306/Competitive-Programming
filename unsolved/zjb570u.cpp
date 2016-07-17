#include <iostream>
using namespace std;
#define N 1100000

static int p[N];
void init(){
	for (int i = 0; i < N; i++)
		p[i] = i;
}
int find(int x){
	return x == p[x] ? x : find(p[x]);
}

struct budget{
	int a, b, d;
};

int main() {
	static int n, m, q, qq[N];
	while (cin >> n >> m){
		init();
		static budget b[N];
		for (int i = 0; i < N; i++)
			b[i].a = b[i].b = b[i].d = 0;
		for (int i = 0; i < m; i++)
			cin >> b[i].a >> b[i].b;
		cin >> q;
		for (int i = 0; i < q; i++){
			cin >> qq[i];
			b[qq[i] - 1].d = 1;
		}
		int tans = n;
		for (int i = 0; i < m; i++)
			if (!b[i].d){
			int fa = find(b[i].a), fb = find(b[i].b);
			if (fa != fb)tans--;
			p[fa] = fb;
			}
		static int ans[N];
		for (int i = q - 1; i >= 0; i--){
			ans[i] = tans;
			int fa = find(b[qq[i]-1].a), fb = find(b[qq[i]-1].b);
			if (fa != fb)tans--;
			p[fa] = fb;
		}
		for (int i = 0; i < q; i++){
			cout << ans[i] << endl;
		}
	}
}