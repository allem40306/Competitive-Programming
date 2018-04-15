#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	int a[4] = { 0, 1, 1, 1 }, c[128] = { 0, 1, 1, 1 };
	long long m = 31;
	int i = 4;
	while (m--){
		c[i++] = (a[0] * a[0] + a[2] * a[1]) % 10007;
		c[i++] = (a[1] * a[0] + a[3] * a[1]) % 10007;
		c[i++] = (a[0] * a[2] + a[2] * a[3]) % 10007;
		c[i++] = (a[1] * a[2] + a[3] * a[3]) % 10007;
		a[0] = c[i - 4], a[1] = c[i - 3], a[2] = c[i - 2], a[3] = c[i - 1];
	}
	while (cin >> n){
		int f0 = 0, f1 = 1, f2, f3;
		m = n, i = 128;
		int d[4];
		int e[4] = { 1, 0, 0, 1 };
		while (m){
			long long ab = 1;
			for (int j = 1; j < i / 4; j++)
				ab *= 2;
			if (ab <= m){
				d[0] = (c[i - 4] * e[0] + c[i - 2] * e[1]) % 10007;
				d[1] = (c[i - 3] * e[0] + c[i - 1] * e[1]) % 10007;
				d[2] = (c[i - 4] * e[2] + c[i - 2] * e[3]) % 10007;
				d[3] = (c[i - 3] * e[2] + c[i - 1] * e[3]) % 10007;
				e[0] = d[0], e[1] = d[1], e[2] = d[2], e[3] = d[3];
				m -= ab;
				i -= 4;
			}
			else
				i -= 4;
		}
		cout << (f0 * d[2] + f1 * d[3]) % 10007 << endl;
	}
}