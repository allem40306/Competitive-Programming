#include<cstdio>
#include<cstring>
// using namespace std;



int main() {
	int n, k, cnt = 0;
	int a[1001]={};

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) { //第幾個人
		for (int j = 1; i <= n; j++) { //燈
			if (j % i == 0)
				a[j] = 1-a[j];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			if (cnt)
				printf(" %d", i);
			else {
				printf("%d", i);
				cnt++;
			}
		}
	}
	return 0;
}
