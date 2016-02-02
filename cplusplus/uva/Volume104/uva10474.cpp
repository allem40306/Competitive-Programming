#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 10010
int a[N], n, q;

int sfind(int qq){
	for (int i = 0; i < n; i++)
		if (a[i] == qq)return i + 1;
	return 0;
}

int main(){
	int t = 1;
	while (cin >> n >> q,n){
		printf("CASE# %d:\n", t++);
		memset(a, -1, sizeof(a));
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a, a + n);
		for (int j = 1,q1; j <= q; j++){
			cin >> q1;
			if (sfind(q1))printf("%d found at %d\n", q1, sfind(q1));
			else printf("%d not found\n", q1);
		}
	}
}