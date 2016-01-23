#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	int i, i1, j, j1, mac, count;
	while (cin >> i >> j){
		i1 = i; j1 = j; mac = 0;
		if (i1 > j1) swap(i1, j1);
		for (int m = i1; m <= j1; m++){
			int m1 = m;
			count = 1;
			while (m1 > 1){
				if (m1 % 2)m1 = m1 * 3 + 1;
				else m1 /= 2;
				count++;
			}
			if (mac < count)mac = count;
		}
		cout << i << ' ' << j << ' ' << mac << endl;
	}
}