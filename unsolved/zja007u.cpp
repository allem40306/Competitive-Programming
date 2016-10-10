#include <iostream>
using namespace std;

int main(){
	unsigned long long int a, b;
	while (cin >> a){
		for (b = 2; b*b <= a; b++)
			if (!(a%b))break;
		printf(b*b > a ? "質數\n" : "非質數\n");
	}
}