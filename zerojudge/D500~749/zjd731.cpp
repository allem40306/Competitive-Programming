#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool lt(int a, int b) {
	return abs(a) > abs(b);
}

int main() {
	static int f[500000];
	int p, n, i, c, j;
	cin >> p;
	while (p--) {
		c = 1;
		cin >> n;
		for (i = 0; i != n; i++)
			cin >> f[i];
		sort(f, f + n, lt);	
		for (i = 1; i<n; i++){
			if ((f[i] >0 && f[i -1]< 0) || (f[i] <0 && f[i - 1]> 0))
				c++;
		}
		cout << c << endl;
	}
}
