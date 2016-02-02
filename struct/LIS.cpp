#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define S 1005

void init(int a[]){
	for (int i = 0; i < S; i++){
		a[i] = 1;
	}
}

int main() {
	int tc, t = 1;
	cin >> tc;
	while (tc--){
		int n, m[S];
		cin >> n;
		for (int i = 0; i < n; i++)cin >> m[i];
		int lis[S];
		init(lis);
		int maxx = 1;
		for (int i = 0; i < n; i++) {
			for (int j = j=i + 1; j < n; j++)
				if (m[i] < m[j])lis[j] = max(lis[j], lis[i] + 1);
		}
		for (int i = 0; i < n; i++) maxx = max(maxx, lis[i]);
		printf("%d\n", maxx);
		int oo[S], mm = maxx;
		for (int p=n-1; p >= 0; p--){
			if (lis[p] == maxx){
				oo[maxx] = m[p];
				maxx--;
			}
		}
		for (int o = 1; o <= mm; o++){
			if (o>1)printf(" ");
			printf("%d", oo[o]);
		}
		cout << endl;
	}
}