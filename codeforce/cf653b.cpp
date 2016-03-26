#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define N 1000000
string a[N/10], ans[N];
char b[N/10];
int ar, n, q;

void init(){
	ar = 0;
	for (int i = 0; i < N; i++){
		a[i%100] = ans[i] = "";
		b[i%100] = ' ';
	}
}

void find(string s){
	int lens = s.size();
	if (lens == n){
		ans[ar++] = s;
		return;
	}
		for (int k = 0; k <q; k++){
			if (s[0] == b[k]){
				find(a[k]+s.substr(1,lens-1));
			}
		}
	return;
}

int main() {
	while (cin >> n >> q){
		init();
		for (int i = 0; i < q; i++)cin >> a[i] >> b[i];
		for (int j = 0; j < q; j++){
			if (b[j] == 'a'){
				find(a[j]);
			}
		}
		sort(ans, ans + ar);
		int ansk = 1, k = 1;
		for (; k < ar; k++)
			ansk += ans[k] != ans[k - 1];
		if (ar == 0)ansk = 0;
		printf("%d\n", ansk);
	}
}