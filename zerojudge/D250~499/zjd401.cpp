#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000005
int a[N],b[N];

void init(){
	for (int i = 0; i < N; i++)
		a[i] = b[i] = 0;
	return;
}

bool cmp(int a, int b){
	if (a!=b)
	return a > b;
}

int main() {
	int n, x, y, k;
	while (cin >> n){
		init();
		int ar = 0, br = 0;
		for (int i = 0; i < n; i++){
			cin >> x >> y;
			if (x == 1)a[ar++] = y;
			else b[br++] = y;
		}
		sort(a, a + ar,cmp);
		sort(b, b + br,cmp);
		cin >> k; k--;
		if (a[k]>b[k])printf("%d %d\n", 1, a[k]-b[k]);
		else printf("%d %d\n", 2, b[k]-a[k]);
	}
}