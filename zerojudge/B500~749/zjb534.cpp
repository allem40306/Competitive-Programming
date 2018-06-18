#include <iostream>
#include <cstring>
using namespace std;
#define N 100000
bool ox[N];
int p[N], pr = 0;

void prime(){
	memset(ox, 0, sizeof(ox));
	ox[0] = ox[1] = 1;
	for (int i = 2; i < N; i++){
		if (!ox[i])p[pr++] = i;
		for (int j = 0; i*p[j] < N&&j < pr; j++)
			ox[i*p[j]] = 1;
	}
}

void detail(int n){
	int t = 0, np = 0;
	for (int i = 0; i < pr; i++){
		if (n == 1)break;
		t = 0;
		while (n%p[i] == 0){ t++; n /= p[i]; }
		if (t){
			if (np++)printf("*");
			printf("%d", p[i]);
			if (t>1)printf("^%d", t);
		}
	}
	if (n != 1){
		if (np++)printf("*");
		printf("%d", n);
	}
	printf(" ,");
}

int gcd(int a, int b){
	int t;
	if (a < b)t = b, b = a, a = t;
	while (t = a%b)a = b, b = t;
	return b;
}

int main() {
	prime();
	int n, ni = 0, a, b, c;
	for (cin >> n; ni < n; ni++){
		cin >> a >> b;
		detail(a);
		c = gcd(a, b);
		printf(" %d , ", c);
		printf(ox[c] ? "N\n" : "Y\n");
	}
}