#include <iostream>
using namespace std;
#define N 15000
#define M 10005
int ox[N], p[N], pr, f[M];

void PrimeTable(){
	ox[0] = ox[1] = 1;
	pr = 0;
	for (int i = 2; i < N; i++){
		if (!ox[i]) p[pr++] = i;
		for (int j = 0; i*p[j]<N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

bool is_prime(int i){
	if (i % 2 == 0)return 0;
	for (int j = 0; j<pr&&p[j]<i; j++)
		if (!(i%p[j]))return 0;
	return 1;
}

void go(){
	int i;
	for (i = 0; i<M; i++)
		f[i] = is_prime(i*i + i + 41);
}

int main(){
	PrimeTable();
	go();
	int n, m,i; double ff;
	while (scanf("%d %d", &n, &m) != EOF){
		ff = 0;
		for (i = n; i <= m; i++)
			if (f[i])ff += 1.0;
		printf("%.2lf\n", ff*100 / (m - n+1)+(1e-9));
	}
}
