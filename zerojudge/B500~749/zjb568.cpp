#include <iostream>
using namespace std;
#define N 1500000

int main() {
	int n, x;
	static bool a[N] = {};
	a[0] = true;
	while (cin >> n){
		while (n--){
			cin >> x;
			for (int i = 1400000; i >= x; i--){
				if (a[i - x])
					a[i] = true;
			}
			for (int j = 700001; j <= 1400000; j++){
				if (a[j]){
					a[j - 700000] = true;
					a[j] = false;
				}
			}
		}
		for (int k = 700000; k >= 0; k--){
			if (a[k]){
				printf("%d\n", k);
				break;
			}
		}
	}
}