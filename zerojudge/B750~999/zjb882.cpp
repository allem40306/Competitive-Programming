#include <iostream>
using namespace std;

int main() {
	int h, m, s;
	cin >> h >> m >> s;
	h = ((h % 24) + (m / 60)) % 24;
	m = ((m % 60) + (s / 60));
	s%= 60;
	h = ((h % 24) + (m / 60)) % 24;
	m %= 60;
	printf("%.2d:%.2d:%.2d\n", h, m, s);
}