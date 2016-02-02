#include <iostream>
#include <string>
using namespace std;

int d_and_c(int a, int b){
	int c;
	if (b == 0)return 1;
	if (b == 1)return a;
	c = d_and_c(a, b / 2);
	if (b % 2 == 0)return c*c;
	return c*c*a;
}

int main(){
	int a, b;
	while (cin >> a >> b){
		cout << d_and_c(a, b) << endl;
	}
}