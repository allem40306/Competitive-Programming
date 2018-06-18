#include <iostream>
using namespace std;
#define N 35000
#define ULL unsigned long long

int main(){
	ULL poss[N] = {1}, coin[5] = { 1, 5, 10, 25, 50 };
	for (int i = 0; i < 5; i++)
		for (int j = coin[i]; j < N; j++)
			poss[j] += poss[j - coin[i]];
	int n;
	while (cin >> n){
		if (poss[n] == 1)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %llu ways to produce %d cents change.\n", poss[n], n);
	}
}