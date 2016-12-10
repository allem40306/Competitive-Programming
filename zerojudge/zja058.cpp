#include <iostream>
using namespace std;
int main(){
	int n, a, d, d1, d2;
	cin >> n;
	d = 0;
	d1 = 0;
	d2 = 0;
	while (n--){
		cin >> a;
		if (a % 3 == 0)d += 1;
		else if (a % 3 == 1)d1 += 1;
		else d2 += 1;
	}
	cout << d << " "<< d1 << " "<< d2;
}
