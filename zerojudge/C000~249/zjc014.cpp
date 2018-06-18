#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b, a || b){
		int o = 0, x = 0;
		while (a || b){
			x = (a % 10 + b % 10 + x) / 10;
			a /= 10; b /= 10;
			o += x;
		}
		if (o == 0)cout << "No carry operation.\n";
		else if (o == 1)cout << "1 carry operation.\n";
		else cout << o << " carry operations.\n";
	}
}
