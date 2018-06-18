#include <iostream>
using namespace std;

int main(){
	int n, i = 0;
	for (cin >> n; i < n; i++){
		int a[5], b[5], ans = 0;
		char ch;
		cin >> a[0] >> ch >> a[1] >> ch >> a[2] >> ch >> a[3] >> ch >> a[4];
		cin >> b[0] >> ch >> b[1] >> ch >> b[2] >> ch >> b[3] >> ch >> b[4];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				ans += a[i] == b[j];
		printf("%d\n", ans);
	}
}