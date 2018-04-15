#include <iostream>
using namespace std;
int main(){
	int n,t;
	while (cin >>n){
		t = 0;
		while (n >= 5){
			n = n / 5;
			t = t + n;
		}
		cout << t << endl;
	}
}