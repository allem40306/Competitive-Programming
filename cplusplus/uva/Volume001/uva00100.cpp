#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int cycle(int x){
	int len = 1;
	while (x > 1){
		if (x % 2 == 1)x = x * 3 + 1;
		else x /= 2;
		len++;
	}
	return len;
}

int main(){
	int i, j;
	while (cin >> i >> j){
		int a = max(i, j), b = min(i, j);
		int maxc = 0;
		for (int x = b; x <= a; x++)
			maxc = max(maxc, cycle(x));
		printf("%d %d %d\n", i, j, maxc);
	}
}