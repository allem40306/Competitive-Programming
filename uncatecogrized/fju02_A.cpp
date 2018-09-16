#include <iostream>
using namespace std;

int main() {
	int n, m, k, t1, t2;
	cin >> n >> m >> k;
	cin >> t1;
	while (--m) {
		cin >> t2;
		if (abs(k - t1) == abs(k - t2)) {
			cout << "Same\n";
		} else if (abs(k - t1) > abs(k - t2)) {
			cout << "Hotter\n";
		} else {
			cout << "Colder\n";
		}
		t1 = t2;
	}
}
