#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 100000
int a[N];

int twofind(int l, int r, int x){
	int m = (l + r) / 2;
}

int main(){
	int k, n, x;
	while (cin >> n >> k){
		memset(a, -1, sizeof(n));
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int j = 0; j < k; j++){
			cin >> x;
			twofind(0, n-1, x);
		}
	}
}