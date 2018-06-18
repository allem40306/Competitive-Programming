#include <iostream>
using namespace std;

int gcd(int a, int b){
	int t;
	while (a < b)t = a, a = b, b = t;
	while (t = a%b)a = b, b = t;
	return b;
}

int main(){
	int x1, x2, y1, y2;
	while (cin >> x1 >> y1 >> x2 >> y2){
		int b, a2, a1, c, i;
		b = (x2 - x1)*(x2 - x1); a2 = y2 - y1;
		i = gcd(b, a2);
		b /= i; a2 /= i; a1 = -2 * a2*x1; c = a2*x1*x1 + y1*b;
		printf("%dy = %dx^2 + %dx + %d\n", b, a2, a1, c);
	}
}