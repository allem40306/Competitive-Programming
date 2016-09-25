#include <iostream>
using namespace std;
#define MOD 10007

int main() {
	unsigned long long  tmp,a, b;
	while (cin >> a >> b){
		tmp = 1;
		while (b){
			if (b & 1)tmp = tmp*a%MOD;
			a = a*a%MOD;
			b >>= 1;
		}
		printf("%lld\n", tmp);
	}
}