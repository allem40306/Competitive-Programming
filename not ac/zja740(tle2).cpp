#include <iostream>
#include <cstring>
using namespace std;
#define N 20000000
int  p[N], pr;
bool ox[N];

void PrimeTable() {
	memset(ox, true, sizeof(ox));
	pr = 0;
	for (int i = 2; i < N; i++) {
		if (ox[i]) p[pr++] = i;
		for (int j = i*i; j<N; ox[j] = false, j += i);
	}
}

int main() {
	PrimeTable();
	int n;
	while (cin >> n) {
		int sum = 0;
		for (int i = 0; p[i] <= n; i++)
			while (n%p[i] == 0) {
			sum += p[i];
			n /= p[i];
			}
		cout << sum << endl;
	}
}