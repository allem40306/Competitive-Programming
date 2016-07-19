#include <iostream>
using namespace std;
#define MOD 100000007

int times(int a, int b, int k){
	int c = a + b;
	for (int i = 0; i <= k; i++){
		c = (a + b) % MOD;
		a = b; b = c;
	}
	return c;
}

int main(){
	int m, f, k;
	while (cin >> m >> f >> k){
		cout << times(m, f, k) % MOD << endl;
	}
}
