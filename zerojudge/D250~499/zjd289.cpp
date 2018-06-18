#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 8
#define M 8010

int main(){
	int i, j, n;
	unsigned int coin[N] = { 1, 13, 33, 43, 139, 169,1309, 2597 };
	unsigned long long int poss[M] = { 1 };
	for (i = 0; i < N; i++)
		for (j = coin[i]; j < M; j++){
			poss[j] += poss[j - coin[i]];
		}
	while(cin >> n){
		cout << poss[n] << endl;
	}
}