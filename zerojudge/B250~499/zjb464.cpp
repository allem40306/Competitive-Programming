#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double  n, r;
	cin >> r >> n;
	int f = round(double(n / r));
	printf("%d:%02d\n", f / 60, f % 60);
}