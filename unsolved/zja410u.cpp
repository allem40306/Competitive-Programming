#include <iostream>
#include <string>
#include <sstream>
using namespace std;

double det(long long a, long long b, long long c, long long d){
	return a*d - c*b;
}

int main() {
	long long a, b, c, d, e, f;
	while (cin >> a, b, c, d, e, f){
		double de = det(a, b, c, d);
		printf("x=%.2f\ny=%.2f\n", det(a, c, d, f) / de, det(b, c, e, f) / de);
	}
}