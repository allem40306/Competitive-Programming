#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, color[N];

struct Point {
	int x, y;
	double rad;
	bool operator<(const Point& b)const {
		return rad < b.rad;
	}
	bool Left(const Point b)const {
		return x * b.y - y * b.x >= 0;
	}
} a[N], b[N];

int sol() {
	if (n <= 2)return 2;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			b[k].x = a[j].x - a[i].x;
			b[k].y = a[j].y - a[i].y;
			if (color[j]) {b[k].x = -b[k].x; b[k].y = -b[k].y;}
			b[k].rad = atan2(b[k].y, b[k].x);
			k++;
		}
		sort(b, b + n - 1);
		int L = 0, R = 0, cnt = 2;
		while (L < k) {
			if (L == R) {
				R = (R + 1) % k;
				cnt++;
			}
			while (L != R && b[L].Left(b[R])) {
				R = (R + 1) % k;
				cnt++;
			}
			cnt--;
			ans = max(ans, cnt);
			L++;
		}
	}
	return ans;
}

int main() {
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y >> color[i];
		}
		cout << sol() << '\n';
	}
}