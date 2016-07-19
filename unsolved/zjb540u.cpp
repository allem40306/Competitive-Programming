#include <iostream>
using namespace std;
#define m(a) a*a
int main(){
	int a[6], b[6];
	while (cin >> a[0]){
		for (int i = 1; i < 6; i++)cin >> a[i];
		int rs = 0, r = -1, ans = 0;
		for (int i = 0; i < 6; i++){
			b[i] = a[(i + 5) % 6] + a[i] + a[(i + 7) % 6];
			if (b[i]>rs)rs = b[i], r = i;
		}
		ans = m(rs - a[(r + 5) % 6]) + m(rs - a[(r + 7) % 6]) + m(rs - a[(r + 3) % 6]);
		printf("%d\n", ans);
	}
}
