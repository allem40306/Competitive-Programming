#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	unsigned long long a, b, c, t;
	int T;
	cin >> T;
	while (T--){
		cin >> a >> b >> c;
		if (a > c)t = a, a = c, c = t;
		if (a > b)t = a, a = b, b = t;
		if (b > c)t = b, b = c, c = t;
		unsigned long long  x = a*a, y = c*c-b*b;
		if (x > y)printf("acute triangle\n");
		else if (x == y)printf("right triangle\n");
		else printf("obtuse triangle\n");
	}
}