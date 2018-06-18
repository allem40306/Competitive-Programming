#include <iostream>
using namespace std;
#define ULL unsigned long long
#define N 1000

int main(){
	ULL m[10] = { 1, 5, 10, 30, 50, 70, 100, 110,500 };
	ULL poss[N] = {};
	for (int i = 0; i <N; i++)
		for (int j = 0; j < 10;j++)
			if (i + m[j] < N){
		if (!poss[i + m[j]])
			poss[i + m[j]] = i ? poss[i] + 1 : 1;
		else if (poss[i + m[j]]>poss[i] + 1)
			poss[i + m[j]] = poss[i] + 1;
			}
	poss[0] = 0;
	int t, n, i = 0;
	for (cin >> t; i < t; i++){
		cin >> n;
		printf("%d\n", n / N + poss[n%N]);
	}
}