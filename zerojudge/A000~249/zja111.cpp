#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	while (cin >> n, n){
		cout << n*(n + 1)*(2 * n + 1) / 6 << endl;
	}
}