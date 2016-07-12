#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define al(x,y) (x+y)*(y-x+1)/2

int main(){
	int n, i, j;
	while (cin >> n){
		int nn = n;
		i = 0;
		while (i < nn){
			i++;
			nn -= i;
		}
		i += (nn > 0);
		j = n - al(1, i - 1);
		if (i % 2)printf("TERM %d IS %d/%d\n", n, i + 1 - j, j);
		else printf("TERM %d IS %d/%d\n", n, j, i + 1 - j);
	}
}