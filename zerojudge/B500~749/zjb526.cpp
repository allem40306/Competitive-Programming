#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005

int main(){
	int a[N] = {}, n, m, i, ans = 0;
	cin >> n >> m;
	for (i = 2, a[1] = n; i < 2 * m + 2; i++){
		cin >> a[i];
		a[i] -= !(i % 2);
	}
		sort(a, a + 2 * m + 2);
		for (i = 0; i < 2 * m + 2; i+=2){
			ans += a[i + 1] - a[i];
		}
		printf("%d\n", ans);
}