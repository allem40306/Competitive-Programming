#include <iostream>
using namespace std;
#define S 35 //stair ¶¥±è
int f[S] = { 1, 0, 3 };

int main() {
	for (int i = 4; i < 31; i += 2)
		f[i] = 4 * f[i - 2] - f[i - 4];
	int n;
	while (cin >> n&&n >= 0)
		cout << f[n] << endl;
}