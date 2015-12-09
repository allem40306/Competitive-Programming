#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	double h, u, d, f, bh, fac;
	int day;
	while (cin >> h >> u >> d >> f, h){
		bh = h; day = 0; fac = u*f / 100;
		while (h > 0){
			day++; h -= u;
			if (h < 0) {
				cout << "success on day " << day << endl;
				break;
			}
			h += d;
			if (h > bh){
				cout << "failure on day " << day << endl;
				break;
			}
			u = u - fac;
			if (u < 0) u = 0;
		}
	}
}
