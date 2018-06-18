#include <iostream>
#include <algorithm>
using namespace std;
#define N 600000

struct xy{
	int x, y;
	bool b = 1;
}a[N];

bool cmp(xy a, xy b){
	if (a.y != b.y)
		return a.y > b.y;
	return a.x > b.x;
}

int main() {
	int n, nt = 0, i;
	while (cin >> n){
		for (i = 0; i < n; i++){
			cin >> a[i].x >> a[i].y;
			a[i].b = 0;
		}
		sort(a, a + n, cmp);
		int nn = 1;
		xy k = a[0]; a[0].b = 1;
		for (i = 1; i < n; i++){
			if (a[i].y != k.y&&a[i].x > k.x){
				k = a[i];
				a[i].b = 1;
				nn++;
			}
		}
		printf("Case %d: \nDominate Point: %d\n", ++nt, nn);
		for (int i = 0; i < n; i++)
			if(a[i].b)printf("(%d,%d)\n", a[i].x, a[i].y);
	}
}