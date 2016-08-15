#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 1005

int lcm(int a, int b){
	if (a < 0)a *= -1;
	if (b < 0)b *= -1;
	int aa = a, bb = b, t;
	if (a < b)t = a, a = b, b = t;
	while (t = a%b){ a = b, b = t; }
	return aa / b*bb;
}

int cau(int a, int b, char ch){
	if (ch == '+')return a + b;
	if (ch == '-')return a - b;
	if (ch == '*')return a * b;
	if (ch == '/')return a / b;
}

int gcd(int a, int b){
	int t;
	if (a < b)t = a, a = b, b = t;
	while (t = a%b){ a = b, b = t; }
	return b;
}

void out(int a, int b){
	if (b < 0)b *= -1, a *= -1;
	if (!a)printf("0\n");
	else if (!(a%b))printf("%d\n", a / b);
	else printf("%d/%d\n", a, b);
	return;
}

int main(){
	int a, b, c, d;
	char ch;
	while (cin >> a >> b >> c >> d >> ch){
		int l = lcm(b, d);
		a *= l / b; c *= l / d;
		int e = cau(a, c, ch);
		if (e == 0)printf("0\n");
		else{
			int g;
			if (ch == '/'){
				g = gcd(a, c);
				out(a / g, c / g);
			}
			else{
				if (ch == '*')l = l*l;
				g = gcd(e, l);
				out(e / g, l / g);
			}
		}
	}
}