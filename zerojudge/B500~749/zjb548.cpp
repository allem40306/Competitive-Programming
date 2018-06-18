#include <iostream>
#include <cstring>
using namespace std;
#define N 5
int a[N][N];
int r[12], n[26];

void tag(int x, int y){
	r[x]++;
	r[y + 5]++;
	if (x == y)r[10]++;
	if (x + y == 4)r[11]++;
	return;
}

int np(int x, int y){
	int p = 0;
	if(r[x]==4)p++;
	if(r[y + 5]==4)p++;
	if (x == y&&r[10]==4)p++;
	if (x + y == 4&&r[11]==4)p++;
	return p;
}

int main(){
	memset(r, 0, sizeof(r));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
		cin >> a[i][j];
		n[a[i][j]] = i * 10 + j;
	}
	int a;
	while (cin >> a, a != -1){
		tag(n[a] / 10, n[a] % 10);
		n[a] = -1;
	}
	int maxp = 0, ans = -1;
	for (int i = 1; i <= 25; i++){
		if (n[i] == -1)continue;
		int p = np(n[i] / 10, n[i] % 10);
		if (p > maxp){ ans = i; maxp = p; }
	}
	printf("%d\n", ans);
}