#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define N 10
#define M 50010

int main(){
	unsigned int i, j;
	unsigned int coin[N] = { 1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000 };
	unsigned long long int poss[M] = { 1 };
	for (i = 0; i < N; i++)
		for (j = coin[i]; j < M; j++)
			poss[j] += poss[j - coin[i]];
	string s;
	while (getline(cin, s), s != "0"){
		int sum = 0, sum2;
		istringstream is(s);
		while (is >> sum2){
			sum += sum2;
		}
		cout << poss[sum] - 1 << endl;
	}
}