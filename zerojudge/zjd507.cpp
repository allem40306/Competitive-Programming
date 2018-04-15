#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t[3];
	while (cin >> t[0]>>t[1]>>t[2]){
		sort(t, t + 3);
		if (t[0] * t[0] + t[1] * t[1] < t[2] * t[2])
			cout << "obtuse triangle\n";
		else if (t[0] * t[0] + t[1] * t[1] > t[2] * t[2])
			cout << "acute triangle\n";
		else
			cout << "right triangle\n";
	}
}