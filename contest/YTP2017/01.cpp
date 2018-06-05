#include <stdio.h>

int main() {
	int N, p[5050] = {1, 1}, i, j, k;
	for (i = 2; i <= 5000; i++)
		if (!p[i])
			for (j = 2; i*j <= 5000; j++)
				p[i*j] = 1;
	for (; ~scanf("%d", &N); puts(""))
		for (k = p[N], i = N; i > 0; i--)
			if (p[i] == k)
				printf("%d ", i);
}
