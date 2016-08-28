#include <iostream>
using namespace std;
int main() {
	int m;
	while (cin >> m){
		cout << (m*(m*m+5)/6+1) << endl;
	}
}