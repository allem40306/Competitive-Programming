#include <iostream>
#include <algorithm>
using namespace std;
#define N 20

int main() {
	int n, m, i;
	cin >> n;
	while (n--){
		int a[N];
		cin >> m;
		for (i = 0; i < 4; i++)cin >> a[i];
		for (i = 4; i < m; i++)a[i] = a[i - 1] + a[i - 4];
		sort(a, a + m);
		cout << a[m / 2] << endl;
	}
}