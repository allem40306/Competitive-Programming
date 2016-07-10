#include <iostream>
using namespace std;

int main(){
	long long x;
	while (cin >> x){
		int h = 0;
		while (x>0){ h++; x -= h; }
		printf("%d\n", h);
	}
}