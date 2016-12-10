#include <iostream>
using namespace std;
int main() {
	int y;
	while (cin >> y){
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			cout << "¶|¦~\n";
		else
			cout << "¥­¦~\n";
	}
}
