#include <stdio.h>

int main(){
	int i, n;
	long long arr[101];
	arr[1] = 1; arr[2] = 2;
	for (i = 3; i<100; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	while (scanf("%d", &n) == 1)
		printf("%lld\n", arr[n]);

	return 0;
}