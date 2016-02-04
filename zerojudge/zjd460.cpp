#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	cout << (a >= 6) * 590 + (a >= 12) * 200 + (a >= 18) * 100 - (a >= 60) * 491;
}