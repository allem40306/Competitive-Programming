#include <iostream>
#include <cstring>
using namespace std;
#define N 20000005

int main() {
	unsigned long long t, n, ti = 0, sum, km[1000];
	static bool a[N];
	for (cin >> t; ti < t; ti++) {
		memset(a, false, sizeof(a)); sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> km[i];
			sum += km[i];
		}
		a[0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = sum; j >= km[i]; j--) {
				if (a[j - km[i]])a[j] = true;
			}
		}
		unsigned long long k = sum / 2;
		for (; !a[k]; k--);
		cout << k*k + (sum - k)*(sum - k) << endl;
	}
}