#include <iostream>
using namespace std;
int main() {
	int  a, b, c, d, t;
	t = 9;
	while (cin >> a >> b >> c >> d){
		if (a == 0 && b == 0 && c == 0 && d == 0) break;
		cout << 80 * t + t*(a - b + 40 * (a<b)) + t * 40 + t*(c - b + 40 * (c<b)) + t*(c - d + 40 * (c<d)) << endl;
	}
}