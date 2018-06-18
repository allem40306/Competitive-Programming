#include <iostream>
using namespace std;
int main(){
	int a, b, c, d;
	while (cin >> a >> b){
		c = (a - b + 100) % 100;
		d = (b - a + 100) % 100;
		if (a == -1 && b == -1)break;
		else if (c > d)c = d;
		cout << c << endl;
	}
}