#include <iostream>
using namespace std;

int main(){
	int a,aa, b;
	while (scanf("%d.%d", &a, &b)!=EOF){
		aa = a; a = a * 100 + b;
		a *= (aa <= 100 ? 9 : (aa <= 500 ? 8 : 6));
		if (aa < 100)a += 8000; a /= 10;
		cout << "$" << a / 100 << ((a % 100 < 10) ? ".0" : ".") << a % 100 << endl;
	}
}
