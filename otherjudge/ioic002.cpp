#include <iostream>
using namespace std;

int main(){
	int a, b, x, t,i=0;
	for (cin >> t; i < t; i++){
		cin >> x;
		if (x >= 1000)printf("1000 %d\n", x - 1000);
		else printf("0 %d\n", x);
	}
}