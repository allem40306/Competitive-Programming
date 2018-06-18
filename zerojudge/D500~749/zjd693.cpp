#include <iostream>
using namespace std;

int main(){
	long long int a, b, t,p, n,x,y;
	while (cin >> n, n){
		cin >> a;
		while (--n){
			cin >> b;
			x = a, y = b;
			while (b){
				t = a%b, a = b, b = t;
			}
			p = x*y / a, a = p;
		}
		cout << a << endl;
	}
}