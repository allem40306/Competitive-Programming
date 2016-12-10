#include <iostream>
#include <algorithm>
using namespace std;
#define N 50
#define M 100000005
int a[N], n, m, na;
bool b[N];

void dp(int r, int t){
	if (t == m){
		na++;
		int i = 0, j = 0;
		for (; i < N; i++){
			if (b[i]){
				if (j++)printf(" ");
				printf("%d", a[i]);
			}
		}
		printf("\n");
		return;
	}
	for (int i = r; i < n; i++){
		if (a[i] + t <= m){
			b[i] = 1;
			dp(i + 1, a[i] + t);
			b[i] = 0;
		}
	}
	return;
}

int main() {
	while (cin >> n >> m){
		for (int i = 0; i < N; i++)a[i] = M, a[i] = false;
		for (int j = 0; j < n; j++)
			cin >> a[j];
		sort(a, a + n);
		na = 0;
		dp(0,0);
		if (!na)printf("-1\n");
	}
}
