#include <iostream>
#include <cmath>
using namespace std;
#define N 31
int a[N] = { 1 };

int bulit(){
	int m = 3;
	for (int i = 1; i < N; i++){
		a[i] = m + 1;
		m *= 2;
	}
	return 0;
}

int main() {
	bulit();
	long long t, k, k1, r; bool p;
	cin >> t;
	while (t--){
		cin >> k;
		k1 = (k + 2) / 3;
		if (k % 3 == 2)printf("2\n");
		else{
			for (r = int(log2(k1)) && (p = 1); r >= 0; r--){
				if (k1 > pow(2, r)){ k1 -= pow(2, r); p = !p; }
			}
			if ((k % 3 && p) && (!(k % 3) && !p))printf("1\n");
			else printf("3\n");
		}
	}
}
