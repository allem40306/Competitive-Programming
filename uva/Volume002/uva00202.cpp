#include <iostream>
#include <cstring>
using namespace std;
#define N 3005
#define Min(x,y) x<y?x:y
int main(){
	int x, y;
	while (cin >> x >> y){
		printf("%d/%d = ", x, y);
		int a[N] = {}, r, r1, mod[N] = { 0 }, re;
		memset(mod, -1, sizeof(mod));
		for (r = 0;; r++){
			a[r] = x / y;
			if (mod[x%y] != -1){ r1 = mod[x%y]; re = r - r1 + 1; break; }
			mod[x%y] = r + 1;
			x = x%y * 10;
		}
		printf("%d.", a[0]);
		for (int i = 1; i < r1; i++)printf("%d", a[i]);
		printf("(");
		for (int i = 0, j = Min(50, re); i < j; i++)
			printf("%d", a[r1 + i]);
		if (re > 50)printf("...");
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n", re);
	}
}