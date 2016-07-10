#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 2000000

int main(){
	int n, r;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			cin >> r;
			int a[N] = {}, m;
			long long ans = 0;
			for (int j = 0; j < r; j++)
				cin >> a[j], a[j] *= 2;
			sort(a, a + r);
			if (r % 2 == 0)m = (a[r / 2 - 1] + a[r / 2]) / 2;
			else m = a[r / 2];
			for (int k = 0; k < r; k++)
				ans += abs(a[k] - m);
			printf("%lld %d\n", ans / 2, r % 2 ? a[r / 2] / 2 : a[r / 2 - 1] / 2);
		}
	}
}
