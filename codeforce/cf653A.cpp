#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 55

int main() {
	int n;
	while (cin >> n){
		int t[N];
		for (int i = 0; i < n; i++)cin >> t[i];
		sort(t, t + n);
		bool flag = 0;
		for (int j = 0; j < n - 2; j++){
			if (flag)break;
			int t2 = 0;
			for (int k = j + 1; k < n; k++){
				if (t[k] - t[j] > 2 || flag)break;
				if (t[k] == t[j] || t2 == t[k])continue;
				if (t2)flag = 1;
				else t2=t[k];
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	}
}