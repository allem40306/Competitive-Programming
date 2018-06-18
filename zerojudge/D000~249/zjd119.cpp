#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 10
#define M 50010

int main(){
	unsigned int i, j;
	unsigned int coin[N] = { 1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000 };
	unsigned long long int poss[N][M] = { 0 };
	for (i = 0; i < M; i++)poss[0][i] = 1;
	for (i = 0; i < N; i++)poss[i][0] = 1;
	for (i = 1; i < N; i++){
		for (j = 0; j < coin[i]; j++)
			poss[i][j] = poss[i - 1][j];
		for (j = coin[i]; j < M; j++)
			poss[i][j] = poss[i - 1][j] + poss[i][j - coin[i]];
	}
	string s;
	while (getline(cin, s)){
		int sum = 0, sum2;
		istringstream is(s);
		while (is >> sum2){
			sum += sum2;
		}
		if(!sum)break;
		cout << poss[9][sum] - 1 << endl;
	}
}