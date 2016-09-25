#include <iostream>
using namespace std;
#define MOD 100000007

struct dev{
	unsigned long long a, b, c, d;
};

dev mm(dev a, dev b){
	dev c;
	c.a = (a.a*b.a + a.b*b.c) % MOD;
	c.b = (a.a*b.b + a.b*b.d) % MOD;
	c.c = (a.c*b.a + a.d*b.c) % MOD;
	c.d = (a.c*b.b + a.d*b.d) % MOD;
	return c;
}

int main() {
	unsigned long long  k, k1, m, f, m2, f2;
	while (cin >> m >> f >> k) {
		bool ism = 0;
		dev d1 = { 0, 1, 1, 1 }, d2 = { 0, 1, 1, 1 };
		k1 = k;
		if (k){
			for (; k; k >>= 1){
				if (k & 1){
					d2 = (ism ? mm(d1, d2) : d1);
					ism = 1;
				}
				d1 = mm(d1, d1);
			}
			m2 =  m * d2.a + f * d2.b % MOD;
			f2 =  m * d2.c + f * d2.d % MOD;
		}
		printf("%lld\n", (m2+f2)%MOD);
	}
}