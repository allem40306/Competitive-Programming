#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
#define BL(a) a&(-a) 
//#define scanf scanf_s
int n, arr[300000], seg[600000];

void init() {
	memset(arr, 0, sizeof(arr));
	memset(seg, 0, sizeof(seg));
}

void modify(int m, int x) {
	while (m <= n){
		seg[m] += x;
		m += BL(m);
	}
}

int quest(int m) {
	int ans = 0;
	while (m){
		ans += seg[m];
		m -= BL(m);
	}
	return ans;
}

int main() {
	for (int t = 1; scanf("%d", &n), n;t++) {
		if (t>1)printf("\n");
		printf("Case %d:\n", t);
		init();
		for (int i = 1; i <= n; i++){
			scanf("%d", &arr[i]);
			modify(i, arr[i]);
		}
		char ch; 
		int a, b;
		while (cin >> ch, ch != 'E') {
			scanf("%d %d", &a, &b);
			if (ch == 'S') {
				int mo = b - arr[a];
				arr[a] = b;
				modify(a ,mo);
			}
			else if (ch == 'M') {
				printf("%d\n",quest(b)-quest(a-1));
			}
		}
		cin >> ch >> ch;
	}
}