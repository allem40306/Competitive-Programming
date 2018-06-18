#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000

int main() {
	int n;
	while (cin >> n){
		int a = (n - 1) / 81, b = (n - 1) % 81;
		int c = b / 9 + 1, d = b % 9;
		int e = c * 10 + d + 1 * (d >= c);
		for (int i = a + 3; i>0; i -= 2){
			if (i == 1)cout << e / 10;
			else cout << e;
		}
		cout << endl;
	}
}