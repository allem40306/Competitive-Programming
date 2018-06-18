#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n){
		int n1[3010], n2[3010];
		for (int i = 0; i < n; i++)
			cin >> n1[i];
		for (int j = 0; j < n - 1; j++)
			n2[j] = abs(n1[j] - n1[j + 1]);
		sort(n2, n2 + n-1);
		int  flag = 1;
		for (int k = 1; k<n; k++)
			if (k != n2[k - 1]){ flag = 0; break; }
		cout << (flag ? "Jolly\n" : "Not jolly\n");
	}
}

