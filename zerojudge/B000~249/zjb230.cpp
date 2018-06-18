#include <iostream>
using namespace std;
#define N 27005
#define M 1000

int main(){
	int i, j, k, c = 1, arr[N]; bool a[N] = {};
	for (i = 1; i<M; i++)
		for (j = i+1; j<M; j++)
			for (k = j+1; k<M; k++)
				if(i*j + j*k + k*i<2000)a[i*j + j*k + k*i] = 1;
	for (i = 1; i<N; i++)
		if (!a[i])arr[c++] = i;
	for (int n; scanf("%d", &n)!=EOF; printf("%d\n", arr[n]));
}
