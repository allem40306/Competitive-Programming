#include <iostream>
using namespace std;
#define T 101

int max(int x, int y) {
	if (x > y)return x;
	return y;
}

int main() {
	int t;
	while (cin >> t) {
		int g[T] = { 0 }, v, k;
		while (t--) {
			cin >> v >> k;
			for (int j = 100;j >= v;j--)
				g[j] = max(g[j], g[j - v] + k);
		}
		cout << g[100] << endl;
	}
}