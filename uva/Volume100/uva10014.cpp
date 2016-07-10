#include <iostream>
#include <iomanip>
using namespace std;
#define N 5000

int main(){
	int n, t;
	cin >> t;
	for (int ti = 0; ti < t; ti++){
		if (ti)cout << endl;
		float a, b, c[N];
		cin >> n;
		cin >> a >> b;
		float ans = n*a + b;
		for (int i = 1; i <= n; i++)cin >> c[i];
		for (int j = 1; j <= n; j++)
			ans -= 2 * j*c[n + 1 - j];
		cout << fixed << setprecision(2) << ans / (n + 1) << endl;
	}
}