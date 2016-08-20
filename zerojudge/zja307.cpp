#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define S 102

int main() {
	int n, m;
	while (cin >> n){
		bool f = 0;
		if (n < 0){ printf("-"); n *= -1; }
		if (n == 0)printf("0");
		while (n){
			m = n % 10; n /= 10;
			if (m)f = 1;
			if (f || m)printf("%d", m);
		}
		printf("\n");
	}
}