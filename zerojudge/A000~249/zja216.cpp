#include <iostream>
using namespace std;

int main(){
	long long int f[30010] = {}, g[30010]{},n;
	f[1] = 1; g[1] = 1;
	for (int i = 2; i <= 30000; i++){
		f[i] = i + f[i - 1];
	}
	for (int i = 2; i <= 30000; i++){
		g[i] = g[i-1] + f[i];
	}
	while (cin >> n)
		cout << f[n] << " " << g[n] << endl;
}
