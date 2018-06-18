#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	while (cin >> n){
		long long count = (n + 1)*((n + 1) / 2) / 2;
		cout << 3 * (2 * count - 1) - 6 << endl;
	}
}
