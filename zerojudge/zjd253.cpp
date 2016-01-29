#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	unsigned int a, b, i, j;
	unsigned int coin[5] = { 1,5,10,25,50 };
	unsigned long long int poss[7500] = {1};
	for (i = 0; i < 5; i++)
		for (j = coin[i]; j < 7500; j++)
			poss[j] += poss[j - coin[i]];
	while (cin >> a)
		cout << poss[a] << endl;
}
