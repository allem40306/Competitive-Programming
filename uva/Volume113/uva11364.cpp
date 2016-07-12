#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 100

int main() {
	int t, n, a[N];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for (int j = 0; j < n; j++)cin >> a[j];
		sort(a, a + n);
		printf("%d\n", 2*(a[n-1]-a[0]));
	}
}