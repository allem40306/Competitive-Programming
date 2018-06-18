#include <iostream>
#include <cmath>
using namespace std;
#define N 100000007
int main(){
	long long a[4] = { 0, 1, 1, 1 }, c[128] = { 0, 1, 1, 1 };
	long long m = 31;
	int i = 4;
	while (m--){
		c[i++] = (a[0] * a[0] + a[2] * a[1]) % N;
		c[i++] = (a[1] * a[0] + a[3] * a[1]) % N;
		c[i++] = (a[0] * a[2] + a[2] * a[3]) % N;
		c[i++] = (a[1] * a[2] + a[3] * a[3]) % N;
		a[0] = c[i - 4], a[1] = c[i - 3], a[2] = c[i - 2], a[3] = c[i - 1];
	}
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int f0 = 0, f1 = 1;
		i = 128;
		long long d[4];
		long long e[4] = { 1, 0, 0, 1 };
		while (n){
			long long ab = 1;
			for (int j = 1; j < i / 4; j++)
				ab *= 2;
			if (ab <= n){
				d[0] = (c[i - 4] * e[0] + c[i - 2] * e[1]) % N;
				d[1] = (c[i - 3] * e[0] + c[i - 1] * e[1]) % N;
				d[2] = (c[i - 4] * e[2] + c[i - 2] * e[3]) % N;
				d[3] = (c[i - 3] * e[2] + c[i - 1] * e[3]) % N;
				e[0] = d[0], e[1] = d[1], e[2] = d[2], e[3] = d[3];
				n -= ab;
				i -= 4;
			}
			else
				i -= 4;
		}
		cout << (f0 * d[2] + f1 * d[3]) % N << endl;
	}
}