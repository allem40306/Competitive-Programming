#include <iostream>
#include <cstring>
using namespace std;
#define N 60000
#define Max(x,y) x>y?x:y
int main() {
	int n, d, s, a[N][3], b[3], td, ts, th, r[3], i, j, k;
	scanf("%d %d", &n, &d); d *= 60;
	while (n--){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%d", &s);
		while (s--){
			scanf("%d %d %d %d %d %d", &td, &ts, &th, &r[0], &r[1], &r[2]);
			for (i = td * 24 + ts, j = 0; j <= th; j++){
				for (k = 0; k < 3; k++)
					a[(i+j)%d][k] += r[k];
			}
		}
		scanf("%d", &s);
		for (i = 0; i < d; i++)
			for (j = 0; j < 3; j++)
				b[j] = Max(a[i][j], b[j]);
		printf("%d %d %d\n", b[0], b[1], b[2]);
	}
}
