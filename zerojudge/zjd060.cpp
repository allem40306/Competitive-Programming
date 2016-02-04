#include <iostream>
using namespace std;

int main() {
	int m;
	cin >> m;
	cout << (25 - m) + 60 * (m / 26) - 60 * (m / 52);
}