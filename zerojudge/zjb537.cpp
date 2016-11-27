#include <iostream>
#include <algorithm>

int main(){
	int t, n, i, j, k, ti = 0, ni, a[105], ans;
	for (scanf("%d", &t); ti<t; ti++){
		for (scanf("%d", &n), ni = 0, ans = 0; ni<n; ni++)scanf("%d", &a[ni]);
		std::sort(a,a+n);
		for (i = 0; i<n - 2; i++)
			for (j = i + 1; j<n - 1; j++)
				for (k = j + 1; k<n; k++)
					if (a[i] * a[i] + a[j] * a[j] == a[k] * a[k])ans++;
		printf("%d\n", ans);
	}
}
