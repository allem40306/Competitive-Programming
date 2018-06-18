#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int  k;
	while (cin >> k) {
		int x, c, t = 0, maax;
		for (int i = 0; i < k; i++){
			cin >> x >> c;
			t += c + -1 * (c == 0);
			maax = max(maax, t);
		}
		cout << maax << endl;
	}
}
