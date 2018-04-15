#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int b, p, m, r;
	while (cin >> b >> p >> m){
		b %= m;
		r = 1; 
		while (p){
			if (p % 2)
				r = (r*b) % m;
			b = (b*b) % m;
			p /= 2;
		}
		cout << r << endl;
	}
}