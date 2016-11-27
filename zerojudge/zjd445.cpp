#include <cstdio>
#include <cstring>

int main(){
	static unsigned long long a[800]; int n, sum, i, j;
	while (scanf("%u", &n) != EOF){
		sum = n*(n + 1) / 2;
		if (sum % 2)printf("0\n");
		else {
			memset(a, 0, sizeof(a));
			a[0] = 1;
			for (i = 0; i<n; i++)
				for (j = sum; j - i >= 0; j--)
					a[j] += a[j - i];
			printf("%d\n", a[sum / 2] / 2);
		}
	}
}
