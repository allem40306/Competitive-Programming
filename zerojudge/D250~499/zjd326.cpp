#include <iostream>
using namespace std;
#define N 32

int main() {
	int v, a, b, arr[N];
	while (cin >> v >> a >> b){
		for (int i = 0; i < N; i++)arr[i] = 0;
		int ar = 0, n = 0;
		if (v < 0){ n = 1; v *= -1; }
		while (v){
			arr[ar++] = v % 2;
			v /= 2;
		}
		if (n){
			int vi = 0, vj = 0;
			for (; vi < N; vi++)arr[vi] = 1 - arr[vi];
			while (1){
				if (vj == N)break;
				arr[vj]++;
				if (arr[vj] > 1)arr[vj] = 0;
				else break;
				vj++;
			}
		}
		arr[a] = b;
		for (int j = N-1; j >= 0; j--)
			printf("%d", arr[j]);
		printf("\n");
	}
}