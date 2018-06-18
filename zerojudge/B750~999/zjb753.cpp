#include <iostream>
#include <string>
using namespace std;
#define N 30
int a[N] = { 10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33 };

int main() {
	int n;
	while (cin >> n){
		string s[N] = {};
		int b[N] = { 0 };
		int x = 0, y = 0, z = 0;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			if (s[i][1] > '2'){ z++; continue; }
			for (int j = 0; j < i; j++)
				if (s[j] == s[i] && b[j]){ y++; b[i] = 1; break; }
			if (!b[i]){
				int v1 = a[s[i][0] - 'A'];
				v1 = v1 / 10 + v1 % 10 * 9;
				for (int ii = 1; ii < 9; ii++)
					v1 += (s[i][ii] - '0')*(9 - ii);
				v1 += (s[i][9] - '0');
				if (v1%10)z++;
				else { x++; b[i] = 1; }
			}
		}
		printf("%d,%d,%d\n", x, y, z);
	}
}