#include <iostream>
#include <set>
using namespace std;
int n, m, a[25],ans;
bool isprime(int i){
	int j=2;
	while(j*j<=i)if(i%j==0)return 0;else j++;
	return 1;
}
void solve(int i, int j, int k) {
	if (j == m) {
		if (isprime(i))ans++;
		return;
	}
	for (; k<n; k++)
		solve(i + a[k], j + 1, k + 1);
}

int main() {
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i<n; i++)scanf("%d", &a[i]);
		ans = 0;
		solve(0, 0, 0);
		printf("%d\n", ans);
	}
}
