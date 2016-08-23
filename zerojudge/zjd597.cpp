#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int combine(int c, int k){
	int com = 1, i;
	for (i = k + 1; i <= c; i++)com *= i;
	for (i = 2; i <= c - k; i++)com /= i;
	return com;
}

int main(){
	int n, k, a[10], i, j, k2;
	while (cin >> n >> k){
		for (i = 0; i < k; i++)cin >> a[i];
		int nc = 0, ans[10];
		bool next = 1;
		while (next){
			int nn = n;
			for (j = k - 1; j >= 0; j--,nn--)
				if (a[j] != nn){ break;}
			if (j == -1)next = 0;
			if (next){
				a[j]++;
				for (j = j + 1; j < k; j++)
					a[j] = a[j - 1] + 1;
				if (!nc)
				for (j = 0; j < k; j++)
					ans[j] = a[j];
			nc++;
			}	
		}
		printf("%d\n", combine(n, k) - nc);
		if (nc){
			for (i = 0; i < k; i++){
				if (i)printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		}
		else
			printf("no next combination\n");
	}
}