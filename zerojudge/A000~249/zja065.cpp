#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	char d1, d2;
	int n;
	while (cin >> d1){
		for (int i = 6; i > 0; i--){
			cin >> d2;
			cout << abs(d2 - d1);
			d1 = d2;
		}
		cout << endl;
	}
}
