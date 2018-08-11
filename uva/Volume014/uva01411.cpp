#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
int Left[N];
double w[N][N], Lx[N], Ly[N];
bitset<N> vx, vy;

bool match(int i) {
	vx[i] = true;
	for (int j = 1; j <= n; j++) {
		if ((fabs(Lx[i] + Ly[j] - w[i][j]) < 1e-9) && !vy[j]) {
			vy[j] = 1;
			if (!Left[j] || match(Left[j])) {
				Left[j] = i;
				return true;
			}
		}
	}
	return false;
}

void update() {
	double a = 1e30;
	for (int i = 1; i <= n; i++) {
		if (vx[i])for (int j = 1; j <= n; j++) {
				if (!vy[j])a = min(a, Lx[i] + Ly[j] - w[i][j]);
			}
	}
	for (int i = 1; i <= n; i++) {
		if (vx[i])Lx[i] -= a;
		if (vy[i])Ly[i] += a;
	}
}

void KM() {
	for (int i = 1; i <= n; i++) {
		Left[i] = Lx[i] = Ly[i] = 0;
		for (int j = 1; j <= n; j++) {
			Lx[i] = max(Lx[i], w[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		while (1) {
			vx.reset(); vy.reset();
			if (match(i))break;
			update();
		}
	}
}

int main() {
	bool f = 0;
	int x1[N], y1[N], x2[N], y2[N];
	while (cin >> n) {
		for (int i = 1; i <= n; i++)cin >> x1[i] >> y1[i];
		for (int i = 1; i <= n; i++)cin >> x2[i] >> y2[i];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				w[j][i] = -sqrt((double)(x1[i] - x2[j]) * (x1[i] - x2[j]) + (double)(y1[i] - y2[j]) * (y1[i] - y2[j]));
				}
		}
		KM();
		if (f)cout << '\n'; f = 1;
		for (int i = 1; i <= n; i++) {
			cout << Left[i] << '\n';
		}
	}
}
