#include <iostream>
using namespace std;
#define N 65536
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

int is_prime(int n){
	if (n == 1)return 1;
	for (int i = 0; n > p[i]&&i<pr; i++)
		if ((n / p[i] != 1) && !(n%p[i]))return 1;
	return 0;
}

int main() {
	PrimeTable();
	int n;
	while (cin >> n, n)
		if (n>2&&n % 2 == 0)cout << 1 << endl;
		else cout << is_prime(n) << endl;
}