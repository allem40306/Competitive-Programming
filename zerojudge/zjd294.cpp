#include <iostream>
#include <string>
using namespace std;


int mn(int a) {
	if(a==1)return 1;
	return a*(a - 1) / 2;
}

int main() {
	int m, n;
	while (cin >> n >> m)
		cout << mn(n + 1)*mn(m + 1) << endl;
}