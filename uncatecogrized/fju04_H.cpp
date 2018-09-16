#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int main() {
	static int n, a[N];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n); //[a,a+n)
	cout << a[n - 1] + a[n - 2] + a[n - 3] << '\n';
}
