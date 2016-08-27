#include <iostream>
using namespace std;
#define N 100005
int a[N];

int binfind(int q, int L, int R){
	int M = (L + R) / 2;
	if (q == a[L])return L;
	if (q == a[R])return R;
	if (R - L < 2)return 0;
	if (q == a[M])return M;
	if (q < a[M])return binfind(q, L, M);
	return binfind(q, M, R);
}

int main(){
	int n, m, q;
	while (cin >> n >> m){
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++){
			cin >> q;
			printf("%d\n", binfind(q,1,n));
		}
	}
}