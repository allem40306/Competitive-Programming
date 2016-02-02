#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
#define BL(a) a&(-a) 
#define N 4000000
//#define scanf scanf_s
int n, arr[N], seg[N];
string a;

void init() {
	memset(arr, 0, sizeof(arr));
	memset(seg, 0, sizeof(seg));
	a = "";
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
	int t, i;
	for (i=1,cin>>t; i<=t; i++) {
		int m, tt;
		string s;
		for (cin >> m; m; m--){
			cin >> tt >> s;
			while (t--)a += s;
		}
		for (int len = a.size(), j = 0; j < len; j++){
			arr[j] =int(s[i] - '0');
			modify(j, arr[j]);
		}

	}
}