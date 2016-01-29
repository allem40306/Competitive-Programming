#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	unsigned int a, b, i, j;
	unsigned int coin[] = { 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };
	unsigned long long int poss[6001] = {1};
	for (i = 0; i < 11; i++)
		for (j = coin[i]; j < 6001; j++)
			poss[j] += poss[j - coin[i]];
	char ch;
	while (cin >> a >> ch >> b, a+b){
		cout <<setw(3)<< a;
		cout << ch;
		if (b < 10)cout << 0;
		cout<< b;
		if (b == 0&&b>10)cout << 0;
		cout << setw(17) << poss[(100 * a + b) / 5]<<endl;
	}
}

