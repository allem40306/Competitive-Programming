#include <iostream>
#include <cstdio>
using namespace std;


int main() {
	int t, n;
	while (cin >> n){
		int tmp = 1, ans = 1;
		while (1){
			if (tmp%n == 0)break;
			tmp %= n;
			tmp = tmp * 10 + 1;
			ans++;
		}
		printf("%d\n", ans);
	}
}