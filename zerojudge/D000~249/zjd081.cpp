#include <iostream>
using namespace std;

int main(){
	int d;
	while (cin >> d){
		int s = 1, a = 1,d1=1;
		for (int i = 1; i < 50; i ++){
			a += d1;
			s += a;
			d1 += d;
		}
		cout << s << endl;
	}
}