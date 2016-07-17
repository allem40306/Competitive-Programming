#include <iostream>
using namespace std;

int main() {
	int a[4], n, b[4];
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]){
		cin >> n;
		while (n--){
			cin >> b[0] >> b[1] >> b[2] >> b[3];
			int na = 0, nb = 0;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (a[i] == b[j]){
						if (i == j)na++;
						else if (a[i] != b[i] && a[j] != b[j])nb++;
					}
			printf("%dA%dB\n", na, nb);
		}
	}
}