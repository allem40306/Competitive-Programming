#include <iostream>
using namespace std;

int main() {
	int a[4], n, b[4];
	while (scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])==4){
		cin >> n;
		while (n--){
			scanf("%d %d %d %d", &b[0], &b[1], &b[2], &b[3]);
			int na = 0, nb = 0, aa[4] = {}, bb[4] = {}, ab[4] = {};
			for (int i = 0; i < 4; i++)
				if (a[i] == b[i])na++, ab[i]= 1;
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 4; j++){
					if (i==j||ab[i]||ab[j]||aa[i]||bb[j])continue;
					if (a[i] == b[j]){ nb++; aa[i] = bb[j] = 1; break; }
				}
			}

			printf("%dA%dB\n", na, nb);
		}
	}
}
