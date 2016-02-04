#include <iostream>
using namespace std;

int main() {
	int a, b, c, teacher;
	cin >> a >> b >> c;
	teacher = a;
	if (teacher < b)
		teacher = b;
	if (teacher < c)
		teacher = c;
	cout << teacher;
}