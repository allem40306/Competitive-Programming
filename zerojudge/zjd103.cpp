#include <iostream>
#include <string>
using namespace std;

int main() {
	char d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, cs, ch;  //cs (checksum)--檢查碼
	while (cin >> d1 >> ch >> d2 >> d3 >> d4 >> ch >> d5 >> d6 >> d7 >> d8 >> d9 >> ch >> d10) {
		cs = (d1 * 1 + d2 * 2 + d3 * 3 + d4 * 4 + d5 * 5 + d6 * 6 + d7 * 7 + d8 * 8 + d9 * 9 - '0' * 45) % 11 + '0';
		if (cs > '9')
			cs = 'X';
		if (cs == d10)
			cout << "Right\n";
		else
			cout << d1 << ch << d2 << d3 << d4 << ch << d5 << d6 << d7 << d8 << d9 << ch << cs << endl;

	}
}