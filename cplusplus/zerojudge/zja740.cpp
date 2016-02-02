#include <iostream>
using namespace std;
#define N 15000
int ox[N], p[N], pr;

void PrimeTable() {
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++) {
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

int main() {
	PrimeTable();
	int n;
	while (cin >> n) {
		int sum = 0;
		for (int i = 0; i<pr&& p[i] <= n; i++)
			while (n%p[i] == 0) {
			sum += p[i];
			n /= p[i];
			}
		cout << sum + (n>1)*n << endl;
	}
}
