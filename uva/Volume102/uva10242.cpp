#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
	point() {};
	point(double a, double b): x(a), y(b) {}
};


int main() {
	point a, b, c, d;
	while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y) {
		if (a.x == c.x && a.y == c.y)swap(a, b);
		if (a.x == d.x && a.y == d.y) {
			swap(a, b);
			swap(c, d);
		}
		if (b.x == d.x && b.y == d.y)swap(c, d);
		cout << fixed << setprecision(3) << a.x + d.x - c.x << ' ' << a.y + d.y - c.y << '\n';
	}
}