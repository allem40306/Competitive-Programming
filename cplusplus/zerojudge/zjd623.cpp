#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	float a[4];
	while (cin >> a[0]>>a[1]>>a[2]>>a[3]){
		if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)break;
		int x = a[0] * a[3] - a[1] * a[2];
		if (x == 0)printf("cheat!\n");
		else printf("%.5f %.5f\n%.5f %.5f\n", a[3] / x, -a[1] / x, -a[2] / x, a[0] / x);
	}
}