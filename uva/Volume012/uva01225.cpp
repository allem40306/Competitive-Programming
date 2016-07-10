#include<cstdio>

int c[10000][10];

int main()
{
	int i, k, t, n;
	for (i = 1; i < 10000; ++i)
	{
		for (k = i; k; k /= 10) ++c[i][k % 10];
		for (; k < 10; ++k) c[i][k] += c[i - 1][k];
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < 9; ++i)
			printf("%d ", c[n][i]);
		printf("%d\n", c[n][9]);
	}
	return 0;
}