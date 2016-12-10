#include <iostream>
#include <algorithm>                            //for sort
using namespace std;

bool cmp(int a, int b) {
	if (a % 10 != b % 10)
		return a % 10 < b % 10;
	return a / 10 > b / 10;
}

int main() {
	int i, n, a[10000];
	while (cin >> n ) {
		for (i = 0; i<n; i++)
			cin >> a[i];
		sort(a, a + n, cmp);
		for (i = 0; i<n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}
