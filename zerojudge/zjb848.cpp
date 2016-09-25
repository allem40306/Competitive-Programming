#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MOD 1000007
#define Max(x,y) x>y?x:y

struct dev{
	unsigned long long a, b, c, d;
};

dev m(dev a, dev b){
	dev c;
	c.a = (a.a*b.a + a.b*b.c) % MOD;
	c.b = (a.a*b.b + a.b*b.d) % MOD;
	c.c = (a.c*b.a + a.d*b.c) % MOD;
	c.d = (a.c*b.b + a.d*b.d) % MOD;
	return c;
}

int main() {
	unsigned long long t, k, k1;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		unsigned long long  a[2][2];
		bool ism = 0;
		dev d1 = { 2, 1, 1, 0 }, d2 = { 2, 1, 1, 0 };
		cin >> a[0][0] >> a[0][1] >> k;
		k1 = k;
		if (k){
		a[1][0] = a[0][1] + 2 * max(a[0][1], a[0][0]);
		a[1][1] = a[0][0];
		for (k--; k;k >>= 1){
			if (k & 1){
				d2 = (ism?m(d1, d2):d1);
				ism = 1;
			}
			d1 = m(d1, d1);
		}
		a[0][0] = (k1 != 1 ?(a[1][0] * d2.a + a[1][1] * d2.b) % MOD : a[1][0]);
		a[0][1] = (k1 != 1 ?(a[1][0] * d2.c + a[1][1] * d2.d)%MOD:a[1][1]);
		}
		printf("%lld %lld\n", a[0][0], a[0][1]);
	}
}