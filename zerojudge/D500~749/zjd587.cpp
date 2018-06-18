#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	while (cin >> n){
		int a[3] = {};
		while (n--){ cin >> m; a[m - 1]++; }
		int out = 0;
		for (int i = 0; i < 3; i++){
			while (a[i]--){
				if (out)printf(" ");
				out++;
				printf("%d", i + 1);
			}
		}
		printf("\n");
	}
}