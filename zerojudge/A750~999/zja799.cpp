#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n)
		cout << (n > 0 ? n : -1*n) << endl;
}

