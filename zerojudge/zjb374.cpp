#include <iostream>
#include <algorithm>
using namespace std;
#define N 30005

struct tot{
	int n, c;
}a[N];

void init(){
	for (int i = 0; i < N; i++)
		a[i].n = i, a[i].c = 0;
	return;
}

bool cmp(tot a, tot b){
	if (a.c != b.c)
		return a.c > b.c;
	return a.n < b.n;
}

int main() {
	int n, m;
	while (cin >> n){
		init();
		for (int i = 0; i < n; i++){
			cin >> m;
			a[m].c++;
		}
		sort(a + 1, a + 30000, cmp);
		for (int i = 1; i < N; i++){
			if (a[i].c != a[1].c)break;
			printf("%d %d\n",a[i].n, a[i].c);
		}
	}
}