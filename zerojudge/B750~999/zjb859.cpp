#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 20005

struct li {
	int n, h, w;
	bool b;
}e[N];
int t, ti = 0, n, m;

void init() {
	for (int i = 0; i < N; i++) {
		e[i].n = i + 1;
		e[i].b = false;
	}
	return;
}

bool cmp(li a, li b) {
	if (a.h != b.h)
		return a.h > b.h;
	if (a.w != b.w)
		return a.w<b.w;
	return (a.n < b.n);
}

int who(int x) {
	for (int i = 0; i < n; i++) {
		if (e[i].n == x)return i;
	}
}

int main() {
	for (cin >> t; ti < t; ti++) {
		cin >> n >> m;
		init();
		for (int ni = 0; ni < n; ni++) {
			cin >> e[ni].h >> e[ni].w;
		}
		sort(e, e + n, cmp);
		int mh = 0, mw = 0;
		for (int i = 0; i < n; i++) {
			if ((e[i].h != mh&&e[i].w >= mw) || (e[i].h == mh&&e[i].w>mw)) {
				e[i].b = true;
				mh = e[i].h;
				mw = e[i].w;
			}
		}
		int k = who(m), nans = 0;
		bool ans[N];
		memset(ans, 0, sizeof(ans));
		nans = 0;
		for (int i = 0; i < k; i++) {
			if (e[i].b&&e[i].h>e[k].h&&e[i].w>e[k].w) {
				nans++;
				ans[e[i].n] = 1;
			}
		}
		if (!nans) { nans = 1; ans[e[k].n] = 1; }
		cout << nans << endl;
		for (int i = 0, j = 0; i <= n; i++) {
			if (ans[i]) {
				if (j)printf(" ");
				j++;
				cout << i;
			}
		}
		cout << endl;
	}
}
