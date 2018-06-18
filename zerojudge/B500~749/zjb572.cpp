#include <iostream>
using namespace std;

int main() {
	int n, h1, m1, h2, m2, m3;
	cin >> n;
	while (n--) {
		cin >> h1 >> m1 >> h2 >> m2 >> m3;
		int s1 = h1 * 60 + m1+m3, s2 = h2 * 60 + m2;
		if (s1 <= s2)cout << "Yes\n";
		else cout << "No\n";
	}
}