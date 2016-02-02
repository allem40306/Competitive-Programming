#include <iostream>
#include <cmath>
using namespace std;

int main(){
	long long int a, b, c, d;
	while (cin >> a >> b){
		c = a - b;
		d = b - a;
		if (c>0)cout << c << endl;
		else cout << d << endl;
	}
}