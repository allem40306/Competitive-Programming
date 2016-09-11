#include <iostream>
#include <algorithm>
using namespace std;
#define N 100005
int a[N], n, m, q;

bool f(int q){
	int ar = 0, br = 1;
	while (1){
		if (ar == n - 1 || br == n)return 0;
		if (a[br] - a[ar] == q)return 1;
		if (a[br] - a[ar] < q)br++;
		else ar++;
	}
	return 0;
}

int main(){
	while (cin >> n >> m){
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a, a + n);
		for (int j = 0; j < m; j++){
			cin >> q;
			printf(f(q) ? "YES\n": "NO\n");
		}
	}
}