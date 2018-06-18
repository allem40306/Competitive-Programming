#include <iostream>
#include <string>
#include <stack>
using namespace std;
#define N 1000005
int f[N] = { 0, 1 }, a[N] = { 0, 1, 3 };

void bulit() {
	int fr = 1, ar;
	while (f[fr] < N) {
		fr++;
		f[fr] = f[fr - 1] + f[fr - 2];
		a[f[fr]] = fr;
	} 
	for (ar =4 ; ar < N; ar++) {
		a[ar] = a[ar] ? a[ar] : a[ar - 1];
	}
	a[1] = 1;
	return;
}

int main() {
	bulit();
	int t, i = 0, x, y, w;
	for (cin >> t; i < t; i++){
		cin >> x >> y;
		if (x > y)w = x, x = y, y = w;
		if (i)printf("------\n");
		int ans = (y == 1);
		if (x==0||a[x] != a[x - 1])printf("%d\n", f[a[x]]), ans++;
		for (int j = a[x]+1; j <= a[y]; j++)
			printf("%d\n", f[j]);
		if (y == 1)printf("1\n");
		printf("%d\n", a[y] - a[x] + ans);
	}
}