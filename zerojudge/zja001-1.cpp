//a001. «¢Åo by Snail
#include <iostream>
using namespace std;

int main () {
	char ch;
	while (cin >> ch) {
		cout << "hello, " << ch;
		while (ch != '\n') {
			cin.get(ch);
			cout << ch;
		}
	}
}
