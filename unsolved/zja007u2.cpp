#include <iostream>
using namespace std;
#define N 50000
unsigned long long int x, ox[N], p[N], pr;

void PrimeTable(){
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++){
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

bool is_prime(){
	for (int i = 0; p[i] * p[i] <= x; i++)
		if (x%p[i] == 0)return 1;
	return 0;
}

int main(){
	PrimeTable();
	while (cin >> x){
		printf(is_prime() ? "質數\n" : "非質數\n");
	}
}