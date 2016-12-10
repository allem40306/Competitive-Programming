#include <iostream>
using namespace std;

int main() {
	int n, a[50], i;
	while (scanf("%d", &n)){
		if (n == 0)break;
		for (i = 0; i < 50; i++)a[i] = 0;
		i = 0;
		while (n){
			a[i] = n % 2;
			n /= 2;
			i++;
		}
		i = 0;
		while (a[i] == 1)i++;
		printf("%d\n", i);
	}
}
