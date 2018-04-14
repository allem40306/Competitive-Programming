#include <iostream>
#include <algorithm>
using namespace std;
#define N 61
int main(){
	int t, ti = 1;
	while (cin >> t, t){
		int n, m, a[N], s = 0;
		char ch;
		for (int i = 0; i < N; i++)a[i] = -1;
		while (t--){
			cin >> n >> ch >> m;
			while (m != -1){
				a[m] = n;
				cin >> m;
				s++;
			}
		}
		cin >> m >> n;
		int nn = n%s+s;
		if (nn>s)nn -= s;
		while (1){
			if (a[m] != -1)nn--;
			if (!nn)break;
			m = (m == 60 ? 1 : m + 1);
		}
		printf("Case %d: Peter arrives at stop %d by tram %d.\n", ti++, n, a[m]);
	}
}