#include <iostream>
using namespace std;
int main() {
	int t, s, d, p1, p2;
	cin >> t;
	while (t--){
		cin >> s >> d;
		p1 = (s + d);
		p2 = (s - d);
		if (p1 < 0 || p2 < 0 || p1 % 2 == 1 || p2 % 2 == 1)
			cout << "impossible" << endl;
		else
			cout << (p1 / 2) << " " << (p2 / 2) << endl;
	}
}