#include <iostream>
#include <string>
#include <sstream>
using namespace std;

double det(long long a, long long b, long long c, long long d){
	return a*d - c*b;
}

int main() {
	long long a, b, c, d, e, f;
	while (cin >> a >> b >> c >> d >> e >> f){
		double de = det(a, b, d, e), dex = det(c, b, f, e), dey = det(a, c, d, f);
		if (!de){
			if (dex || dey)printf("No answer\n");
			else printf("Too many\n");
		}
		else printf("x=%.2f\ny=%.2f\n",dex/de,dey/de );
	}
}