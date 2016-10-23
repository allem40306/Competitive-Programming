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

bool is_prime(int n){
	for (int i = 0; n >= p[i]*p[i]&&i<pr; i++)
		if ((n / p[i] != 1) && !(n%p[i]))return 0;
	return 1;
}

int main() {
	PrimeTable();
	int n;
	while (cin >> n)
		if ((n>2&&n % 2 == 0)||!is_prime(n))cout << "非質數" << endl;
		else cout << "質數" << endl;
}