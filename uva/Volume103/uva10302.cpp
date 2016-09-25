#include <iostream>
using namespace std;

int main() {
	unsigned long long n;
	while (cin >> n)
		cout << n*n*(n + 1)*(n + 1) / 4 << endl;
}