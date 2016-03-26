#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, a, b, a1, b1;
	while (cin >> n, n){
		cin >> a >> b;
		while (n--){
			cin >> a1 >> b1;
			if (a == a1 || b == b1)printf("divisa");
			else{
				if (b1 > b)printf("N");
				else printf("S");
				if (a1 > a)printf("E");
				else printf("O");
			}
			printf("\n");
		}
	}
}