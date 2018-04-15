#include <iostream>
using namespace std;
int main() {
	int a, b, c,n,z;
	z = 0;
	n = 5;
	while (n--){
		cin >> a >> b >> c;
		if (a + b > c&&a+c>b&&b+c>a) z++;
	}
	cout << z;
}