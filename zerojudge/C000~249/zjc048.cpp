#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
	int m, n, x;
	while (cin >> m, m){
		n = (int)ceil(sqrt(m));
		x = n*n - n + 1;
		if (n % 2 && m >= x || n % 2 == 0 && m <= x)
			cout << n - abs(m - x) << " " << n << endl;
		else
			cout << n << " " << n - abs(m - x) << endl;
	}
}