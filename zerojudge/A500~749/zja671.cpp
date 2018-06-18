#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	double n, p;
	while (cin >> n >> p)
		cout << int(pow(p, 1 / n) + .5) << endl;
}
